from sys import stdin

def main():
    tokens = stdin.readline().split()
    print(int(tokens[0]) + int(tokens[1]))

if __name__ == "__main__":
    main()
