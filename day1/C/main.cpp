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

int fuelNeeded(int weight){
    int fuel = 0;
    fuel = weight/3 -2;
    if (fuel < 0){
        return 0;
    }
    weight = weight - fuel;
    return (fuel);
}


int main(){
    ifstream myfile("input.txt");
    
    if (myfile.is_open()){
        cout << "file openend" << endl;
        while (! myfile.eof()){
            line = "";
            temp = 0;
            getline(myfile, line); //read line
            cout << line << " ";
            istringstream tempint (line); //convert string to int
            tempint >> temp;

            data.push_back(temp); //save data
        }
        cout << endl;
        myfile.close();
    }
    else {cout << "No file found";}
    
    fuel = 0;
    cout << "size: " << data.size();
    for (int weight : data){
        cout << "weight: " << weight << endl;
        int addedFuel = -1;
        while (!addedFuel == 0){
            addedFuel = fuelNeeded(weight);
            weight = addedFuel;
            fuel = fuel + addedFuel;
        }
    }
    cout << "fuel needed: " << fuel << endl;
    return 0;
}

