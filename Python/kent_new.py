'''
Author: Joel Wachsler 2015 - Progolymp - Kent-buggen-improved
'''
from collections import defaultdict

def main():
    n = int(input())
    d = defaultdict(int)
    for x in range(n):
        d[input()] += 1
    print(len([y for x,y in d.items() if y > 1]))

if __name__ == "__main__":
    main()
