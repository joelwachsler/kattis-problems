class Passenger():
    def __init__(self, going, currentStation):
        self.going = going
        self.currentStation = currentStation

    def station(self):
        self.currentStation += 1
        return self.currentStation == self.going

class Buss():
    def __init__(self, capacity):
        self.capacity = capacity
        self.passengers = []
        self.queue = 0
        self.currentStation = 1

    def nextStation(self):
        self.passengers[:] = [x for x in self.passengers if x.station() == False]
        self.currentStation += 1
        #for index in range(len(self.passengers)):
            #if self.passengers[index].station:
                #del self.passengers[index]

    def addPassenger(self, going):
        if self.full():
            self.queue += 1
        else:
            self.passengers.append(Passenger(going, self.currentStation))

    def full(self):
        return self.capacity == len(self.passengers)


def main():
    first_input = input().split()
    stations = int(first_input[0])
    capacity = int(first_input[1])

    buss = Buss(capacity)

    for currentStation in range(stations - 1):
        stationInput = input().split()
        stationInput.pop(0)
        for station in stationInput:
            buss.addPassenger(int(station))
        buss.nextStation()
    print(buss.queue)

if __name__ == "__main__":
    main()
