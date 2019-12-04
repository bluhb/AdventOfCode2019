
# 265275-781584
Begin = 265275
End = 781584

def containDouble(Input):
    InputS = str(Input)
    for i in range(0,len(InputS)-1):
        if int(InputS[i]) == int(InputS[i+1]):
            return True
    return False

def containOnlyDouble(Input):
    InputS = str(Input)
    for i in range(0,len(InputS)):
        if InputS.count(InputS[i]) == 2:
            return True
    return False

def nonDecreasing(Input):
    InputS = str(Input)
    for i in range(0, len(InputS)-1):
        if int(InputS[i+1]) < int(InputS[i]):
            return False
    return True

def main():
    CorrectPass = []
    for i in range(Begin, End+1):
        if containOnlyDouble(i) and nonDecreasing(i):
            CorrectPass.append(i)

    print(len(CorrectPass))
    return 0

if __name__ == "__main__":
    main()
