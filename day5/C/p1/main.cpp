#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <cmath>

//OPcodes: positions are keys for Data.
//
//1: (pos1, pos2, store) pos1+pos2=>store; advance 4 steps
//2: (pos1, pos2, store) pos1*pos2=>store; advance 4 steps
//3: (pos1) pos1 << std::cin; advance 2 steps
//4: (pos1) std::cout << pos1; advance 2 steps


std::vector<int> Data;
std::vector<int> Param;

void readFile(std::string FileName){ //Read in the data file
    std::ifstream MyFile(FileName);
    std::string Line, T;
    int i = 0;
    if (MyFile.is_open()){
        while (! MyFile.eof()){
            Line = "";
            std::getline(MyFile, Line); //read line
            std::stringstream X(Line);
            while (std::getline(X, T, ',')){
                std::stringstream X(T);
                int Z; X >> Z;
                Data.push_back(Z);
            }
            i++;
        }
        MyFile.close();
    }
    else {std::cout << "No file found";}
}

void addOP(int Index, int Mode[]){
    int Val[3];
    for (int i =0; i < 3; i++){
        if (i == 2){
            Val[i] = Data[Index + i + 1];
        }else if (Mode[i] == 0){
            Val[i] = Data[Data[Index + i + 1]];
        }else if (Mode[i] == 1){
            Val[i] = Data[Index + i + 1];
        }
    }
    //std::cout << "Key: " << Val[2] << " = " << Val[0] << " + " << Val[1] << std::endl;
    Data[Val[2]] = Val[0] + Val[1];
}

void multOP(int Index, int Mode[]){
    int Val[3];
    for (int i =0; i < 3; i++){
        //std::cout << "At: " << i << " Mode " << Mode[i] << " ";
        if (i == 2){
            Val[i] = Data[Index + i + 1];
        }else if (Mode[i] == 0){
            Val[i] = Data[Data[Index + i + 1]]; 
            //std::cout<< Val[i] <<std::endl;
        }else if (Mode[i] == 1){
            Val[i] = Data[Index + i + 1];
            //std::cout<< Val[i] <<std::endl;
        }
    }
    //std::cout << "Key: " << Val[2] << " = " << Val[0] << " * " << Val[1] << std::endl;
    Data[Val[2]] = Val[0] * Val[1];
}

void inputOP(int Index, int Mode[]){
    if (Mode[0] == 0){
        int Pos1 = Data[Index+1];
        int Input;
        std::cout << "Give Input please: ";
        std::cin >> Input;
        Data[Pos1] = Input;
    }else{std::cout << "inputOP Error, unknown mode";}
}

void outputOP(int Index, int Mode[]){
    if (Mode[0] == 0){
        std::cout << "OutPut: " << Data[Data[Index+1]] << std::endl;
    }else if (Param.size() > 0){
        std::cout << "OutPut: " << Param[0] << std::endl;
    }
    Param.clear();
}

int parseLongOP(int Instruction, int Index){
    int StepSize = 0; //main will block if this is the case
    int OPCode = Instruction % 100;
    Instruction = (Instruction - OPCode)/100;
    //std::cout << "OP: " << OPCode << std::endl;
    int Mode[3]; 
    Mode[0] = Instruction % 10;
    
    for (int i=100; i<=1000; i = i * 10){
        Mode[int(log10(i) - 1)] = (( (Instruction - Mode[int(log10(i) - 2)]) % i ) / (i / 10));
    }
    //std::cout << "OPCode: " << OPCode << std::endl;
    //std::cout << std::endl;
    
    if ((OPCode == 1) & (Mode[2] == 0)){
        addOP(Index, Mode);
        StepSize = 4;
    }else if((OPCode == 2) & (Mode[2] == 0)){
        multOP(Index, Mode);
        StepSize = 4;
    }else if(OPCode == 3){
        inputOP(Index, Mode);
        StepSize = 2;
    }else if(OPCode == 4){
        outputOP(Index, Mode);
        StepSize = 2;
    }else if(OPCode == 99){
        StepSize = 0;
    }else{
        std::cout << "Error" << std::endl;
        return 0;
    }
   

    return StepSize;
}

int parseShortOP(int Instruction, int Index){
    int StepSize = 0;
    //parser for short opcodes
    return StepSize;}

int main(){
    readFile("input.txt");
    unsigned long i=0;
    int Step = -1;
    while ( ( i < Data.size() ) & !( Step == 0 ) ){
        Step = parseLongOP(Data[i], i);
        i = i + Step;
    }
    std::cout << "Done";
    return 0;
}
