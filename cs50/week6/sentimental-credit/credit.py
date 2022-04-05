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

# find every second number * 2
digits = [int(x) for x in str(cc_num)]
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

if 
# output whether valid or not