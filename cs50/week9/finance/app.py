import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd
from datetime import datetime

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # Retrieve list of transactions for logged in user
    user = session["user_id"]
    transactions = db.execute("SELECT * from transactions WHERE user_id = ?", user)
    name = db.execute("SELECT username from users WHERE id = ?", user)
    cash = db.execute("SELECT cash from users WHERE id = ?", user)
    stocks = db.execute("SELECT symbol, SUM(cost) FROM transactions WHERE user_id = ? GROUP BY symbol", user)

    # render index.html
    return render_template("index.html", transactions = transactions, name = name, cash = cash, stocks = stocks)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")

    # If user reached via POST
    elif request.method == "POST":
        stock = request.form.get("buy")
        stock_details = lookup(stock)

    # Validate stock symbol & store details if valid
        if lookup(stock) != None:
            stock_name = stock_details["name"]
            stock_symbol = stock_details["symbol"]
            stock_price = stock_details["price"]

        else:
            return apology("Invalid Stock Symbol", 403)

        # Validate share amount is a positive integer
        if request.form.get("shares"):
            try:
                shares = int(request.form.get("shares"))
                if shares <= 0:
                    return apology("Not a Valid amount of Shares", 403)

            except ValueError:
                return apology("Please input a positive amount of Shares", 403)

        # Validate whether user has enough cash to make purchase
        user_id = session["user_id"]
        cost = stock_price * shares * (-1)
        current_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

        if current_cash < cost * (-1):
            return apology("Cannot afford this purchase", 403)

        # Record purchase in database
        purchase_time = datetime.now()
        db.execute("INSERT into transactions (user_id, date_time, symbol, shares, cost) VALUES(?, ?, ?, ?, ?)", user_id, purchase_time, stock_symbol, shares, cost)

        # Update users cash value
        new_cash = current_cash + cost
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

        # Redirect to home page
        return redirect("/")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # redirect to stock symbol form
    if request.method == "GET":
        return render_template("quote.html")

    # If user reached via POST then lookup stock and render price
    if request.method == "POST":
        stock = request.form.get("stock")
        stock_details = lookup(stock)

        if lookup(stock) != None:
            stock_name = stock_details["name"]
            stock_symbol = stock_details["symbol"]
            stock_price = usd(stock_details["price"])
            return render_template("quoted.html", stock_price = stock_price, stock_symbol = stock_symbol, stock_name = stock_name)

        else:
            return apology("Invalid stock symbol", 403)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # Redirect user to register form
    if request.method == "GET":
        return render_template("register.html")

    # User reached route via POST
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Ensure password confirmation was submitted
        elif not request.form.get("confirmation"):
            return apology("must confirm password", 403)

        # Ensure password confirmation matches password
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("Passwords do not match")

        # check if username exists already
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        if len(rows) == 1:
            return apology("Username already exists")

        # add username and password to the database
        username = request.form.get("username")
        hash = generate_password_hash(request.form.get("password"))
        new_login = db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)

        # Create session ID for new user login
        session["user_id"] = new_login

        return redirect("/")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
