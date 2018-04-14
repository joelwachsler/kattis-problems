'''
Author: Joel Wachsler - tabbtabbande
'''
from copy import deepcopy
# Antalet tabbar
n = int(raw_input())
# Antalet vaxlingar
m = int(raw_input())
# Vaxla till

array = [1]
for x in range(0, m):
    array.append(int(raw_input()))

#array = (1,2,5,4)

total = 0

def forward(index):
    # Forward
    x = deepcopy(array[index])
    steps = 0
    while x != array[index + 1]:
        if x+1 > n:
            x = 1
        else:
            x += 1
        steps += 1
    return steps

# Backwards
def backward(index):
    x = deepcopy(array[index])
    steps = 0
    while x != array[index + 1]:
        if x == 1:
            x = n
        else:
            x -= 1
        steps += 1
    return steps

for x in range(0, m):
    first = forward(x)
    second = backward(x)

    if first > second:
        total += second
    else:
        total += first

print total
