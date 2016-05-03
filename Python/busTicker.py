# Joel Wachsler - 2015 - Busskortet

def main():
    money_to_fill = int(input())
    transactions = 0
    while money_to_fill > 0:
        transactions += 1
        if money_to_fill >= 500 or money_to_fill + 100 >= 500:
            money_to_fill -= 500
            continue
        elif money_to_fill >= 200 or money_to_fill + 100 >= 200:
            money_to_fill -= 200
            continue
        else:
            money_to_fill -= 100
    print(transactions)


if __name__ == "__main__":
    main()
