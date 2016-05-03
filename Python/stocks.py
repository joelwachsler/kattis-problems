
# Author: Joel Wachsler
# Date: 2015-08-03
# Desc: Borsen

class Purse():
    def __init__(self, days, exchangePrice, stockPriceDay):
        self.cash = 100
        self.stocks = 0
        self.tempCash = 0
        self.tempStocks = 0

        self.stockPriceDay = stockPriceDay
        self.exchangePrice = exchangePrice
        self.currentDay = 0
        self.days = len(stockPriceDay)

    def valid(self):
        return self.currentDay != self.days

    def nextDay(self):
        self.tempStocks = (self.cash - self.exchangePrice) / self.stockPriceDay[self.currentDay]
        self.tempCash = self.stocks * self.stockPriceDay[self.currentDay] - self.exchangePrice

        if self.tempCash > self.cash:
            self.cash = self.tempCash
        if self.tempStocks > self.stocks:
            self.stocks = self.tempStocks

        self.currentDay += 1

def main():
    days = int(input())
    purse = Purse(days, float(input()), [float(input()) for i in range(days)])

    while purse.valid():
        purse.nextDay()

    lastDayPriceTest = purse.stockPriceDay[-1] * purse.stocks - purse.exchangePrice
    if lastDayPriceTest > purse.cash:
        print(lastDayPriceTest)
    else:
        print(purse.cash)

if __name__ == "__main__":
    main()
