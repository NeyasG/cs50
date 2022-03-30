import cs50

while True:
        height = int(input("Height: "))
    if (height.isnumeric() > 0):
        for i in range(1, (height + 1), 1):
            print(" " * (height - i), "#" * (i), sep='')
        break




