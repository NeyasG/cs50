import cs50

while True:
    height = input("Height: ")
    if (height.isnumeric() == True and int(height) < 9 and int(height) > 0):
        for i in range(1, (int(height) + 1), 1):
            print(" " * (int(height) - i), "#" * (i), sep='', end='  ')
            print("#" * (i), sep='',)
        break




    sdjkhgiuashglsdifjangksdfahgiouefhglijandfghlkjfhggidfjhglijh