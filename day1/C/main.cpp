#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;
string line;
list<int> data;
int fuel = 0;
int temp;

int FuelNeeded(int weight){
    int fuel = 0;
    fuel = weight/3 -2;
    if (fuel < 0){
        return 0;
    }
    weight = weight - fuel;
    return (fuel);
}

void ReadFile(string fileName){
    ifstream myfile(fileName);
    
    if (myfile.is_open()){
        cout << "file openend" << endl;
        while (! myfile.eof()){
            line = "";
            temp = 0;
            getline(myfile, line); //read line
            istringstream tempint (line); //convert string to int
            tempint >> temp;

            data.push_back(temp); //save data
        }
        myfile.close();
    }
    else {cout << "No file found";}
}

int main(){
    ReadFile("input.txt");    
    fuel = 0;
    for (int weight : data){
        int addedFuel = -1;
        while (!addedFuel == 0){
            addedFuel = FuelNeeded(weight);
            weight = addedFuel;
            fuel = fuel + addedFuel;
        }
    }
    cout << "fuel needed: " << fuel << endl;
    return 0;
}

