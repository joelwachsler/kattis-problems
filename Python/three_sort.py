from sys import stdin

def main():
    tokens = stdin.readline().split()
    # Convert to integer
    for i in range(3):
        tokens[i] = int(tokens[i])

    # Bubble sort
    for p in range(2):
        for i in range(2):
            if tokens[i+1] <= tokens[i]:
                tokens[i], tokens[i+1] = tokens[i+1], tokens[i]

    print(" ".join(str(e) for e in tokens))

if __name__ == "__main__":
    main()
