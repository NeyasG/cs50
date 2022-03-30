import cs50

height = get_int("Height: ")
    for i in range(1, height, 1):
        print(" " * (height - i), "#" * (i), sep='')
