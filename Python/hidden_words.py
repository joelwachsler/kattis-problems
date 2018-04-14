'''
Author: Joel Wachsler - Gomda ord
'''
import string

# All letters we need
letters = string.uppercase

assoc_array = {}

position = 1
for key in letters:
    assoc_array[key] = position
    position += 1

word = ""
word = raw_input()

dec_word = ""
dec_word += word[0]

def rec(word, letters, index):
    try:
        letters += word[index]
        index += assoc_array[word[index]]
    except IndexError:
        print letters
        return
    rec(word, letters, index)

rec(word, "", 0)
