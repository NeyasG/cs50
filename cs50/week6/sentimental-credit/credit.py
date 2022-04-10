#!/usr/local/bin/python
# called a shebang, has to be first line. Directs OS to interpreter
# test cases, optimal way of inputting test cases?

import re

def digit_sum(number):
    new_num = 0
    if len(str(number)) == 1:
        return number
    else:
        for digit in str(number):
            new_num += int(digit)
        digit_sum(new_num)

# Protects script if imported from being run
if __name__ == "__main__":
    # get user input
    cc_num = input("Number: ")
    regex = r"^(\d{13}|\d{15,16})$"

    # Validate User input
    if re.match(regex, cc_num) is None:
        print("INVALID")
        exit()

    # find every second number * 2
    # List comphrension
    digits = [int(x) for x in cc_num[::-1]]
    y = []

    # Pythonic way of writing loop, no indexes needed
    # every second digit
    for x in digits[1: : 2]:
        y = y + [x * 2]

    # find sum of digits from above
    result = 0
    for elem in y:
        sum_val = 0
        for digit in str(elem):
            sum_val += int(digit)
        result += sum_val

    # add above to sum of remaining digits in cc_num
    # simplified counter
    result += sum(digits[::2])

    # checksum
    if result % 10 != 0:
        print("INVALID")
        exit()

    # output whether valid or not
    if int(cc_num[:2]) == 34 or int(cc_num[:2]) == 37:
        print("AMEX")
    elif int(cc_num[:2]) == 51 or int(cc_num[:2]) == 52 or int(cc_num[:2]) == 53 or int(cc_num[:2]) == 54 or int(cc_num[:2]) == 55:
        print("MASTERCARD")
    elif int(cc_num[:1]) == 4:
        print("VISA")
    else:
        print("INVALID")