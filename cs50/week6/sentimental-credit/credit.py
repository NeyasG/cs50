import re

# get user input
cc_num = input("Number: ")
regex = r"^(\d{13}|\d{15,16})$"

# Validate User input
if re.match(regex, cc_num) == None:
    print("INVALID")
    exit()

# print("VALID") # Debug

# apply algorithm to user input
for digit in str(cc_num):
    print(int(digit))
# output whether valid or not