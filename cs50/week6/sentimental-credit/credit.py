import re

# get user input
cc_num = input("Number: ")
regex = r"^(\d{13}|\d{15,16})$"

# Validate User input
if re.match(regex, cc_num) == None:
    print("INVALID")
    exit()

# reverse cc_num

# apply algorithm to user input
digits = [int(x) for x in str(cc_num)]

for x in range(1, len(cc_num), 2):
    print(cc_num[x])

# output whether valid or not