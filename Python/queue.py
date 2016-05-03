first = input().split()
cart_space = int(first[1])
people_in_queue = [int(x) for x in input().split()]
front_index = 0
queue = 0
real_queue = [0 for x in range(int(first[0]))]

#cart_space = 4
#people_in_queue = [4,3,2,1,1]
#front_index = 0
#queue = 0
#real_queue = [0 for x in range(len(people_in_queue))]

it = iter(people_in_queue)
cart_space_left = cart_space
# Iterator holder
item = 0
index = 0

while len(people_in_queue) > 0:
    if people_in_queue[0] == -1:
        del people_in_queue[0]
        front_index += 1
        it = iter(people_in_queue)
        continue

    try:
        item = next(it)
    except StopIteration:
        queue += 1
        it = iter(people_in_queue)
        item = next(it)
        # Refill cart
        cart_space_left = cart_space

    if item <= cart_space_left:
        cart_space_left -= item
        # Delete item if it's in the front
        index = people_in_queue.index(item)
        if index == 0:
            del people_in_queue[0]
            real_queue[front_index] = queue
            front_index += 1
            it = iter(people_in_queue)
        else:
            people_in_queue[index] = -1
            real_queue[index + front_index] = queue
        if cart_space_left == 0:
            queue += 1
            it = iter(people_in_queue)
            # Refill cart
            cart_space_left = cart_space
for x in real_queue:
    print(x, end=" ")
print()
