'''
Progolymp - Joel Wachsler 2015 - Ramsan
'''
from sys import stdin
import time

def main():
    tokens = stdin.readline().split()
    _ord = int(tokens[0])
    barn = list(range(1, int(tokens[1]) + 1))

    barn_extend = barn.extend
    new = []
    while len(barn) > 1:
        delete = _ord % len(barn)
        del barn[(delete - 1)]
        if delete != 0:
            new = barn[:(delete - 1)]
            del barn[:(delete - 1)]
            barn_extend(new)
    print(barn[0])


if __name__ == "__main__":
    main()
