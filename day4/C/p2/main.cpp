#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

const int Begin = 265275;
const int End = 781584;
std::vector<int> CorrectPass;

bool containOnlyDouble(int Input){
    bool Double = false;
    std::string InputS = std::to_string(Input);
    int Length = InputS.length();
    int InputA[Length];
    for (int i =0; i < Length; i++){
        std::stringstream Temp;
        Temp << InputS[i];
        Temp >> InputA[i];
    }
    for (int i=0; i < Length; i++){
        int Count = std::count (InputA, InputA+Length, InputA[i]);
        if ((Count == 2)){
            Double = true;
        }
    }
    return Double;
}

bool nonDecreasing(int Input){
    std::string InputS = std::to_string(Input);
    int Length = InputS.length();
    for (int i=0; i < Length -1; i++){
        if (int(InputS[i+1]) < int(InputS[i])){
            return false;
        }
    }
    return true;
}

int main(){
    std::cout << "Starting Program" << std::endl;
    for (int i = Begin; i <= End; i++){
        if (containOnlyDouble(i) && nonDecreasing(i)){
            CorrectPass.push_back(i);
        }
    }
    std::cout << CorrectPass.size() << std::endl;
    
    return 0;
}
