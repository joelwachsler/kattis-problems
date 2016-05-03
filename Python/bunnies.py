class Bunnie():
    def __init__(self, currAge, femaleBabies):
        # Antalet kaninhonor i den här generationen
        self.femaleBabies = femaleBabies
        # Hur många månader tills de är könsmogna
        self.currentAge = currAge

    def age(self, Bunnies):
        # En månad har gått
        self.currentAge -= 1
        # Kolla om de här kaninerna är könsmogna
        if self.ready():
            Bunnies.bunniesReady += self.femaleBabies
            return True
        else:
            return False

    def ready(self):
        return self.currentAge == 0

class Bunnies():
    def __init__(self):
        # Input
        user_input = input().split()
        # Hur många månader för att kaninen ska bli könsmogen
        self.readyAge = int(user_input[0])
        # Antalet honor per generation
        self.femalesPerGen = int(user_input[1])
        # Kaniner som inte är könsmogna ännu
        self.bunnies = [Bunnie(self.readyAge, 1)]
        # Kaniner som är könsmogna
        self.bunniesReady = 0

    def age(self):
        self.bunnies[:] = [bunnie for bunnie in self.bunnies if not bunnie.age(self)]
        self.bunnies.append(Bunnie(self.readyAge, self.bunniesReady * self.femalesPerGen))

        self.total()

    def total(self):
        total = self.bunniesReady
        for bunnie in self.bunnies:
            total += bunnie.femaleBabies

        print(total, end=' ')



def main():
    startGen = Bunnies()

    for x in range(10):
        startGen.age()

if __name__ == "__main__":
    main()
