height = ("wrong")

while (isinstance(height)):
    height = int(input("Height: "))
    for i in range(1, height, 1):
        print(" " * (height - i), "#" * (i), sep='')
