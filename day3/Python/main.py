
# Cooradinates stored as [ [ [x,y],[x,y] ] , [ [x,y],[x,y] ] ]

Coordinates = [[(0,0)],[(0,0)]]

def readFile(FileName):
    F = open(FileName, 'r')
    Data = []
    i=0
    for lines in F:
        Temp = lines.rstrip()
        Data.append(Temp.split(','))
        i += 1
    return Data

def add(Dir, Amount, LineNr):
    Current = Coordinates[LineNr][-1]
    for i in range(1,Amount+1):
        if Dir == 'R':
            New = (Current[0] + i, Current[1])
        elif Dir == 'L':
            New = (Current[0] - i, Current[1])
        elif Dir == 'U':
            New = (Current[0], Current[1] + i)
        elif Dir == 'D':
            New = (Current[0], Current[1] - i)
        else:
            raise ValueError('Nondefined direction')
        Coordinates[LineNr].append(New)
    return None

def intersections(Line1,Line2):
    Line1.pop(0)
    Line2.pop(0)
    return list(set(Line1) & set(Line2))

def getManhattanDist(Points):
    ManhattanDistances = []
    for Value in Points:
        Dist = abs(Value[0]) + abs(Value[1])
        ManhattanDistances.append(Dist)
    ManhattanDistances.sort()
    return ManhattanDistances

def getIntSmallestStep(Intersections, Line1, Line2):
    Steps = []
    for Value in Intersections:
        Key1 = Line1.index(Value) + 1 #add one because index start at 0
        Key2 = Line2.index(Value) + 1
        Steps.append(Key1+Key2)

    Steps.sort()
    return Steps

def main():
    Data = readFile("input.txt")
    z=0
    for i in Data:
        for j in i:
            add(j[0], int(j[1:]), z)
        z += 1
    Intersections = intersections(Coordinates[0], Coordinates[1])
    ManhattanDistances = getManhattanDist(Intersections)
    Steps = getIntSmallestStep(Intersections, Coordinates[0], Coordinates[1])
    print ("Smallest ManhattanDistance: " + str(ManhattanDistances[0]))
    print ("Minimum steps to intersect: " + str(Steps[0]))
    return 0

if __name__ == "__main__":
    main()
