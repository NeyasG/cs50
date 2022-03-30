import cs50

dollars = cs50.get_float("How many dollars: ")
remainder = 0;

quarters = int(dollars / 0.25)
remainder = float(dollars - (quarters * 0.25))

print(remainder)