import cs50

while True:
    height = input("Height ")
    if height.isnumeric():
        for i in range(1, height, 1):
            print(" " * (height - i), "#" * (i), sep='')
        break




