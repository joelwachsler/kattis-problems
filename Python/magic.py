'''
Magic
'''
from sys import stdin
from copy import deepcopy

x = int(raw_input())

actions = []
for p in range(0, x):
    data = stdin.readline().split()
    actions.append([data[0], data[1]])

last = 0
#actions = [['-', '1'], ['*', '3'], ['+', '9'], ['/', '2'], ['+', '5'], ['-', 'x']]


def rec(hemligt):
    global actions
    tal = deepcopy(hemligt)
    for y in range(0, x):
        operation = deepcopy(actions[y])
        if operation[1] == 'x':
            operation[1] = float(hemligt)
        else:
            operation[1] = float(operation[1])

        if operation[0] == '-':
            tal -= operation[1]
        elif operation[0] == '+':
            tal += operation[1]
        elif operation[0] == '/':
            tal /= operation[1]
        elif operation[0] == '*':
            tal *= operation[1]
    return tal

broken = False

for p in range(0, 10000):
    if p == 0:
        last = rec(p)
    else:
        if last != rec(p):
            broken = True

if broken:
    print "Nej"
else:
    if last.is_integer():
        print last
    else:
        print "Nej"
