#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

int Data[117];
int Answer = 19690720;

void readFile(string FileName){ //Read in the data file
    ifstream MyFile(FileName);
    string Line;
    int Temp;
    int i = 0;
    if (MyFile.is_open()){
        while (! MyFile.eof()){
            Line = "";
            Temp = 0;
            getline(MyFile, Line); //read line
            istringstream TempInt (Line); //convert string to int
            TempInt >> Temp;
            Data[i] = Temp; //save data
            i++;
        }
        MyFile.close();
        Data[1] = 12;
        Data[2] = 2;
    }
    else {cout << "No file found";}
}



void addOP(int Index){
    int Pos1 = Data[Index+1];
    int Pos2 = Data[Index+2];
    int store = Data[Index+3];

    Data[store] = Data[Pos1] + Data[Pos2];   
}

void multOP(int Index){
    int Pos1 = Data[Index+1];
    int Pos2 = Data[Index+2];
    int store = Data[Index+3];

    Data[store] = Data[Pos1] * Data[Pos2];   
}

int main(){
    for (int x = 0; x <= 99; x++){
        for (int y = 0; y <= 99; y++){
            readFile("input.txt");
            for (int i = 0; i < 117; i = i + 4){
                Data[1] = x;
                Data[2] = y;
                if (Data[i] == 99){
                    break;
                }else if (Data[i] == 1){
                    addOP(i);
                }else if(Data[i] == 2){
                    multOP(i);
                }
            }
            if (Data[0] == Answer){
                cout << "Noun: " << Data[1] << " Verb: " << Data[2] << endl;
                cout << 100*Data[1] + Data[2];
                return 0;
    
            }
        }
    }
    return 0;
}
