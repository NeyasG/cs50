import cs50

dollars = cs50.get_float("How many dollars: ")
remainder = dollars;

quarters = remainder / 0.25
remainder = remainder - quarters

print(remainder, quarters)

dimes = remainder / 0.10
remainder = remainder - dimes

nickels = remainder / 0.05
remainder = remainder - nickels

cents = remainder / 0.01
remainder = remainder - cents

print(quarters + dimes + nickels + cents)