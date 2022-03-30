import cs50



cents = cs50.get_float("Change owed: ")
cents = cents * 100

quarters = int(cents / 25)
cents = cents - quarters * 25

dimes = int(cents / 10)
cents = cents - dimes * 10

nickels = int(cents / 5)
cents = cents - nickels * 5

pennies = int(cents / 1)

print(int(quarters + dimes + nickels + cents))
