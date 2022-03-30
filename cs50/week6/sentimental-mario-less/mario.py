import cs50

while True:
    try:
        height = int(input("Height: "))
    except ValueError:
        continue
    except (height < 1):
        continue
    else:
        for i in range(1, height, 1):
            print(" " * (height - i), "#" * (i), sep='')
        break
