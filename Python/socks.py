# Joel Wachsler 2015
biggest = int(input().split()[1])
my_list = [int(x) for x in input().split()]
my_list.sort()
sum = 0

while len(my_list) > 1:
    if abs(my_list[-1]-my_list[-2]) < biggest:
        sum += 1
        del my_list[-1]
        del my_list[-1]
    elif my_list[-1] > my_list[-2]:
        del my_list[-1]
    else:
        del my_list[-2]

print(sum)
