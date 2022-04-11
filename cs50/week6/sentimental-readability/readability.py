import cs50
import re

# get string from user
text = cs50.get_string("Text: ")

# find number of letters, discounting non alpha chars
letters = len([c for c in text if c.isalpha()])

# split into list then count len of list
words = len(text.split(" "))

# using regex to find delimiters in text
delimiters = ".", "!", "?"
regex = "|".join(map(re.escape, delimiters))
# creates list of sentences then filters out None and finds len
sentences = len(list(filter(None, re.split(regex, text))))

# Find Coleman_Liau Index
CL_index = 0.0588 * (letters / words) * 100 - 0.296 * (sentences / words) * 100 - 15.8

# debug
print(letters)
print(words)
print(sentences)
print(list(filter(None, re.split(regex, text))))
print(CL_index)

# print Grade level
if CL_index >= 16:
    print("Grade 16+")
elif CL_index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(CL_index)}")