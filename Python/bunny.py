'''
Kaniner
'''

antal = 5
final_array = [3, 4, 2, 1, 5]

def move(num, array):
    holder = []
    for x in range(0, num):
        holder.append(array.index(x))
        array.pop(x)
    for x in reversed(holder):
        array.append(x)
    return array

for y in range(1, antal - 1):
    print [x + 1 for x in move(y-1, range(0, antal))]
