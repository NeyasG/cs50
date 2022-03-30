import cs50

dollars = cs50.get_float("How many dollars: ")
dollars = int(dollars * 100)
remainder = 0;

quarters = int(dollars / 25)

print(quarters)