import cs50

cents = cs50.get_float("Change owed: ")

quarters = int(cents / 25)
cents = cents - quarters * 25

nickels = int(cents / )
