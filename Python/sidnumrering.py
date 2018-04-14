import operator

pages = int(input())
cache = dict()

def cacheItem(n, currCounter):
    original = n
    while n:
        if n in dict:
            cache[original] = list(map(operator.add, cache[n], currCounter))
            return
        counter[n % 10] += 1
        n //= 10


for n in range(1, pages, 2):
    if n in cache:
    else
        c = [0,0,0,0,0,0,0,0,0,0]

print(*counter, sep=' ')
