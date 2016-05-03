'''
Progo - Joel Wachsler 2015 - oversattning
'''
from sys import stdin
#import cProfile

def translate(text, dictionary_a, dictionary_b):
    while True:
        original = text[:]
        text = list(dictionary_a[x] for x in text)
        text = list(dictionary_b[x] for x in text)
        if set(text) == set(original):
            return text

if __name__ == "__main__":
    dict_numb = int(input())
    dictionary_a = dict()
    dictionary_b = dict()
    for x in range(dict_numb):
        tokens = stdin.readline().split()
        if tokens[0] not in dictionary_a:
            dictionary_a[tokens[0]] = tokens[1]

        if tokens[1] not in dictionary_b:
            dictionary_b[tokens[1]] = tokens[0]

    numb_word = input()
    text = stdin.readline().split()

    final = translate(text, dictionary_a, dictionary_b)
    #cProfile.run('translate(text, dictionary_a, dictionary_b)')
    
    for x in final:
        print(x, end=" ")

    
