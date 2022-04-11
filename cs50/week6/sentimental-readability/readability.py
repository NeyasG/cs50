import cs50

text = cs50.get_string("Text: ")

letters = len([c for c in text if c.isalpha()])

print(letters)
print(text.count(" "))