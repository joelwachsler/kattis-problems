# Joel Wachsler  - 2015 - Begransningsarea

def main():
    # Pre-calculated data for increased speed
    cache = {0: 0, 1: 6, 2: 10, 3: 14, 4: 18, 5: 22, 6: 26, 7: 30, 8: 34, 9: 38, 10: 42, 11: 46, 12: 50, 13: 54, 14: 58, 15: 62, 16: 66, 17: 70, 18: 74, 19: 78, 20: 82, 21: 86, 22: 90, 23: 94, 24: 98, 25: 102, 26: 106, 27: 110, 28: 114, 29: 118, 30: 122, 31: 126, 32: 130, 33: 134, 34: 138, 35: 142, 36: 146, 37: 150, 38: 154, 39: 158, 40: 162, 41: 166, 42: 170, 43: 174, 44: 178, 45: 182, 46: 186, 47: 190, 48: 194, 49: 198, 50: 202}

    x_y_value = [int(item) for item in input().split()]
    y = x_y_value[0] + 1
    x = x_y_value[1] + 1

    data = []
    append_data = data.append
    for item in range(y - 1):
        append_data([int(input_item) for input_item in input().split()])

    new_data = []
    append_new_data = new_data.append

    for item in data:
        temp = []
        for height in item:
            temp.append(cache[height])
        append_new_data(temp)

    dirs = (
            (0,-1), # Left
            (1,0),  # Up
            (0,1),  # Right
            (-1,0)  # Down
            )

    for y_pos in range(y):
        for x_pos in range(x):
            for direction in dirs:
                if y_pos + direction[0] >= 0 and x_pos + direction[1] >= 0:
                    try:
                        if data[y_pos + direction[0]][x_pos + direction[1]] > data[y_pos][x_pos]:
                            new_data[y_pos][x_pos] -= data[y_pos][x_pos]
                        else:
                            new_data[y_pos][x_pos] -= data[y_pos + direction[0]][x_pos + direction[1]]
                    except IndexError:
                        pass

    print(sum(sum(item) for item in new_data))

if __name__ == "__main__":
    main()
