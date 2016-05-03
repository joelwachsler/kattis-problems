# Author: Joel Wachsler
# Date: 2015-08-02

class Rectangle():
    def __init__(self, persons):
        self.persons = persons
        # Start values of x and y
        self.x = int(persons ** 0.5)
        self.y = int(persons ** 0.5)
        # Holder for true values
        self.works = []
        # We stop after 5 false in a row
        self.falseCounter = 0

    def valid(self):
        return self.falseCounter != 3 and self.x != 1

    def increment(self):
        if (self.x * self.y) >= self.persons:
            self.works.append((self.x, self.y))
            self.falseCounter = 0
            self.x -= 1
        else:
            self.y += 1
            self.falseCounter += 1

    def smallestArea(self):
        return min([(x + 1) * (y + 1) for (x, y) in self.works])

def main():
    rec = Rectangle(int(input()))

    # Default values not needed to be calculated
    knownValues = {1:4,2:6,3:8}
    if rec.persons in knownValues:
        print(knownValues[rec.persons])
        return

    while rec.valid():
        rec.increment()

    print(rec.smallestArea())

if __name__ == "__main__":
    main()
