import cs50

# get string from user
text = cs50.get_string("Text: ")

# find number of letters, discounting non alpha chars
letters = len([c for c in text if c.isalpha()])

words = 

#debug
print(letters)
print(text.count(" "))