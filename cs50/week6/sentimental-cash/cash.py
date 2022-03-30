import cs50

dollars = cs50.get_float("How many dollars: ")
remainder = dollars;

quarters = remainder / 0.25
remainder = remainder - (quarters * 0.25)

print(remainder, quarters)

dimes = remainder / 0.10
remainder = remainder - (dimes * 0.10)

nickels = remainder / 0.05
remainder = remainder - (nickels * 0.05)

cents = remainder / 0.01
remainder = remainder - (cents * 0.01)

print(quarters + dimes + nickels + cents)