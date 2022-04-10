#!/usr/local/bin/python
# called a shebang, has to be first line. Directs OS to interpreter

import re

# get user input
cc_num = input("Number: ")
regex = r"^(\d{13}|\d{15,16})$"

# Validate User input
if re.match(regex, cc_num) == None:
    print("INVALID")
    exit()

# reverse cc_num
cc_num_rev = cc_num[::-1]

# find every second number * 2
digits = [int(x) for x in str(cc_num_rev)]
y = []
for x in range(1, len(cc_num), 2):
    y = y + [digits[x] * 2]

# find sum of digits from above
result = 0
for elem in y:
    sum_val = 0
    for digit in str(elem):
        sum_val += int(digit)
    result += sum_val

# add above to sum of remaining digits in cc_num
for x in range(0, len(cc_num), 2):
    result += sum([digits[x]])

if result % 10 != 0:
    print("INVALID")
    exit()

if int(cc_num[:2]) == 34 or int(cc_num[:2]) == 37:
    print("AMEX")
elif int(cc_num[:2]) == 51 or int(cc_num[:2]) == 52 or int(cc_num[:2]) == 53 or int(cc_num[:2]) == 54 or int(cc_num[:2]) == 55:
    print("MASTERCARD")
elif int(cc_num[:1]) == 4:
    print("VISA")
else:
    print("INVALID")

# output whether valid or not