#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

int Data[117];

void readFile(string FileName){ //Read in the data file
    ifstream MyFile(FileName);
    string Line;
    int Temp;
    int i = 0;
    if (MyFile.is_open()){
        cout << "file openend" << endl;
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
    readFile("input.txt");
    for (int i = 0; i < 117; i = i + 4){
        cout << Data[i] << " ";
        if (Data[i] == 99){
            cout << "Done" << endl;
            for (int x=0; x < 117; ++x){
                cout << Data[x] << " ";
            }
            cout << endl << Data[0];
            return 0;
        }else if (Data[i] == 1){
            addOP(i);
        }else if(Data[i] == 2){
            multOP(i);
        }
    }
    return 0;
}
