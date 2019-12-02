import math

def readFile():
    F = open("input.txt", "r")
    Data = F.readlines()
    return Data

def fuelNeeded(Weight):
    Fuel = 0
    Fuel = math.floor(((Weight/3)-2))
    if Fuel < 0:
        return 0
    return Fuel

def main():
    Data = readFile()
    TotalFuel = 0
    AddFuel = -1
    for Weight in Data:
        AddFuel = -1
        while not (AddFuel == 0):
            AddFuel = fuelNeeded(int(Weight))
            TotalFuel += AddFuel
            Weight = AddFuel
            AddFuel = 0

    print(TotalFuel)
    return None

if __name__ == "__main__":
    main()

