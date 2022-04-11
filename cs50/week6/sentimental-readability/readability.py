import cs50

text = cs50.get_string("Text: ")

print(len(text) - text.count(" "))
print(text.count(" "))