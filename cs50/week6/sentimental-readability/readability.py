import cs50
import re

# get string from user
text = cs50.get_string("Text: ")

# find number of letters, discounting non alpha chars
letters = len([c for c in text if c.isalpha()])

# split into list then count len of list
words = len(text.split(" "))

# using regex to find delimiters
delimiters = ".", "!", "?"
regex = 
sentences =

#debug
print(letters)
print(words)
print(sentences)