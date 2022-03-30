import cs50

dollars = cs50.get_float("How many dollars: ")
dollars = int(dollars * 100)
remainder = dollars;

quarters = remainder / 25
remainder = remainder - quarters

print(remainder, quarters)

dimes = remainder / 10
remainder = remainder - dimes

nickels = remainder / 5
remainder = remainder - nickels

cents = remainder / 1
remainder = remainder - cents

print(quarters + dimes + nickels + cents)