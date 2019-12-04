#include <string>
#include <iostream>
#include <sstream>
#include <vector>

const int Begin = 265275;
const int End = 781584;
std::vector<int> CorrectPass;

bool containDouble(int Input){
    std::string InputS = std::to_string(Input);
    int Length = InputS.length();
    for (int i=0; i < Length; i++){
        if (InputS[i] == InputS[i+1]){
            return true;
        }
    }
    return false;
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
        if (containDouble(i) && nonDecreasing(i)){
            CorrectPass.push_back(i);
        }
    }
    std::cout << CorrectPass.size();
    
    return 0;
}
