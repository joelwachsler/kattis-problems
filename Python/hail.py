'''
Progolymp - Joel Wachsler 2015 - Hagel
'''
from sys import stdin
import time

def loop(a, b, dictionary):
    # Test default values first
    if a == b:
        return 0
    dictionary[a] = 0
    dictionary[b] = 0

    count = 1
    while True:
        if a != 1:
            if a % 2 == 0:
                a /= 2
                a = int(a)
            else:
                a *= 3
                a += 1
            if a in dictionary:
                return (dictionary, a, count)
            else:
                dictionary[a] = count
        if b != 1:
            if b % 2 == 0:
                b /= 2
                b = int(b)
            else:
                b *= 3
                b += 1
            if b in dictionary:
                return (dictionary, b, count)
            else:
                dictionary[b] = count
        count += 1

def main():
    dictionary = dict()
    tokens = stdin.readline().split()
    a = int(tokens[0])
    b = int(tokens[1])
    data = loop(a, b, dictionary)
    if data == 0:
        print(0)
    else:
        print(data[0][data[1]] + data[2])

if __name__ == "__main__":
    main()
