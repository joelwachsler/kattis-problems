'''
Author: Joel Wachsler 2014 - Progo, Vikingar
'''
from sys import stdin

t = int(input())

dictionary = {}
for x in range(t):
    data = stdin.readline().split()
    dictionary[data[1]] = data[0]

input_data = input()

# Split data
input_data = [input_data[x:x+4] for x in range(0, len(input_data), 4)]

for x in range(len(input_data)):
    try:
        print(dictionary[input_data[x]], end='')
    except KeyError:
        print('?', end='')

print()
