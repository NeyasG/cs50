def luhn_validate(card_number):
    luhn_sum = 0
    counter = 0

    card_number_copy = card_number

    while(card_number_copy > 0):
        digit = card_number_copy % 10
        if counter % 2 == 1:
            #counting from the *right*, we double every *second* digit
            digit *= 2
        if digit >= 10:
            #separating and adding together digits of any number 10-20 is the same as subtracting 9
            #e.g. 12 = 1 + 2 = 3 = 12 - 9
            digit -= 9
        #this adds the remaining digits as well
        luhn_sum += digit
        #integer division by 10 shifts all the digits down
        card_number_copy //= 10
        counter += 1

    if luhn_sum % 10 != 0:
        return "INVALID"

    if counter == 13:
        if (4e12 <= card_number < 5e12):
            return "VISA"
    if counter == 15:
        if (34e13 <= card_number < 35e13) or (37e13 <= card_number < 38e13):
            return "AMEX"
    if counter == 16:
        if (4e15 <= card_number < 5e15):
            return "VISA"
        elif (51e14 <= card_number < 56e14):
            return "MASTERCARD"

    return "INVALID"
