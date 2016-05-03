'''
Author: Joel Wachsler 2014 - Progolymp - Kent-buggen
'''
import collections
n = int(input())
wdict = list()
append = wdict.append
for x in range(n):
	append(input())

new_list = tuple([x for x, y in collections.Counter(wdict).items() if y > 1])

print(len(new_list))