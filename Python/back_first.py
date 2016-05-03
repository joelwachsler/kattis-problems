'''
Author: Joel Wachsler 2014 - Programmeringsolympiaden
'''
from sys import stdin
from copy import deepcopy

# Get input
data = stdin.readline().split()

data_rows_north = stdin.readline().split()
data_rows_south = stdin.readline().split()
# Trees on every row
n = int(data[0])
#n = 3
# Trees to get apples from
k = int(data[1])
#k = 14
# Biggest
biggest = 0
# Apple rows
array = []

def prepare(array, data, n):
    for x in xrange(0,n):
        array.append([int(data[x]), True])

prepare(array, data_rows_north, n)
prepare(array, data_rows_south, n)

#array = [   [ 800, True ], [ 300, True ], [ 400, True ],
#            [ 2, True ], [ 500, True ], [ 3, True] ]

def pick(array, index, steps):
    array = deepcopy(array)
    # We are at the last point
    if steps <= 0:
        global biggest
        total = sum(array)
        if total > biggest:
            biggest = total
        return

    global n

    # We have gone one step
    steps -= 1

    # Set current index to false
    array[index][1] = False

    got_one = False
    # North
    if tryIndex(array, index - n):
        got_one = True
        pick(array, index - n, steps)
    # East
    if tryIndex(array, index + 1):
        got_one = True
        pick(array, index + 1, steps)
    # South
    if tryIndex(array, index + n):
        got_one = True
        pick(array, index + n, steps)
    # West
    if index != n and tryIndex(array, index - 1):
        got_one = True
        pick(array, index - 1, steps)

    if got_one == False:
        pick(array, index, 0)

def tryIndex(array, index):
    try:
        if array[index][1] == True and index >= 0:
            # Index is in bounds and we can go there
            return array[index]
        else:
            # The index is false and we have been here before
            return False
    except IndexError:
        # Index is out of bounds
        return False

def sum(array):
    total = 0
    for (value, walked) in array:
        if walked == False:
            total += value
    return total

pick(array, n, k)

print biggest