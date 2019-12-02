
def readFile():
    F = open("input.txt", "r")
    Data = []
    for Line in F:
        Data.append(int(Line.rstrip()))
    return Data

def addOP(Index, Data):
    Pos1 = Data[Index + 1]
    Pos2 = Data[Index + 2]
    Store = Data[Index + 3]

    Data[Store] = Data[Pos1] + Data[Pos2]
    return Data

def multOP(Index, Data):
    Pos1 = Data[Index + 1]
    Pos2 = Data[Index + 2]
    Store = Data[Index + 3]

    Data[Store] = Data[Pos1] * Data[Pos2]
    return Data

def main():
    for x in range(0,99):
        for y in range(0,99):
            Data = readFile()
            Data[1] = x
            Data[2] = y
            for i in range(0, len(Data), 4):
                if Data[i] == 99:
                    break
                if Data[i] == 1:
                    Data = addOP(i, Data)
                elif Data[i] == 2:
                    Data = multOP(i, Data)
            if Data[0] == 19690720:
                print(f"Noun {Data[1]}, Verb {Data[2]}")
                print(Data[1]*100+Data[2])

    print(f"Data 0: {Data[3]}")
    print(i)
    return None

if __name__ == "__main__":
    main()
