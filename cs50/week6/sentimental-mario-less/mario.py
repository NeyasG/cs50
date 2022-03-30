import cs50

while True:
    height = input("Height: ")
    if (height.isnumeric() > 0):
        height = int(height)
        for i in range(1, (height + 1), 1):
            print(" " * (height - i), "#" * (i), sep='')
        break




