import re

# get user input
cc_num = input("Number: ")
regex = r"^(\d{13}|\d{15,16})$"

# Validate User input
if re.match(regex, cc_num) == None:
    print("INVALID")
    exit()

# reverse cc_num
cc_num = cc_num[::-1]

# apply algorithm to user input
digits = [int(x) for x in str(cc_num)]
print(digits)
y = 0
for x in range(1, len(cc_num), 2):
    y.append = [digits[x]]

print(y)

# output whether valid or not