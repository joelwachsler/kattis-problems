'''
Muffins
'''

muffins = int(raw_input())

a = 0
b = 0

one = 0
two = 0

def day(a_or_b, muffins):
    global one, two
    over = muffins % 2
    muffins = muffins - over
    
    half = muffins / 2
    muffins = muffins - half
    if a_or_b:
        one += over + half
    else:
        two += over + half

    if muffins > 0:
        if a_or_b:
            a_or_b = False
        else:
            a_or_b = True
        day(a_or_b, muffins)

day(False, muffins)
print one, two
