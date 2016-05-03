# Author: Joel Wachsler
# Date: 2015-08-03
# Desc: Bokhyllor

class Hylla():
    def __init__(self, small, medium, big, shelfCap):
        self.small = small
        self.medium = medium
        self.big = big
        self.shelfCap = shelfCap
        self.shelfs = 1
        self.currentShelfBooks = shelfCap

    def active(self):
        return self.small != 0 or self.medium != 0 or self.big != 0

    def fillBig(self):
        while self.currentShelfBooks >= 3 and self.big > 0:
            self.currentShelfBooks -= 3
            self.big -= 1

    def fillMedium(self):
        while self.currentShelfBooks >= 2 and self.medium > 0:
            self.currentShelfBooks -= 2
            self.medium -= 1

    def fillSmall(self):
        while self.currentShelfBooks >= 1 and self.small > 0:
            self.currentShelfBooks -= 1
            self.small -= 1

    def reset(self):
        if self.active():
            self.currentShelfBooks = self.shelfCap
            self.shelfs += 1


def main():
    booksInput = input().split()
    hylla = Hylla(int(booksInput[0]), int(booksInput[1]), int(booksInput[2]), int(input()))
    while hylla.active():
        hylla.fillBig()
        hylla.fillMedium()
        hylla.fillSmall()
        hylla.reset()

    print(hylla.shelfs)

if __name__ == "__main__":
    main()
