# Author: Joel Wachsler
# Date: 2015-08-03
# Desc: Full Tank

stops = int(input())

maxPrice = []
minPrice = []

dataIn = ''
gas = 0
money = 0
for i in range(stops):
    dataIn = input().split()
    gas = int(dataIn[0])
    money = int(dataIn[1])

    maxPrice.append(round((money + 4.99) / gas, 2))
    minPrice.append(round((money - 5) / gas, 2))

gasPrice = (min(maxPrice) + max(minPrice)) / 2
print(round((gasPrice * int(input()) + 4.99) / 10) * 10)
