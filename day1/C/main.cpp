#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;
int fuel;

int FuelNeeded(int weight){ //calculate needed fuel for given weight
    int f = 0;
    f = weight/3 -2;
    if (f < 0){
        return 0;
    }
    return (f);
}

list<int> ReadFile(string fileName){ //Read in the data file
    ifstream myfile(fileName);
    list<int> data;
    string line;
    int temp;
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
    return (data);
}

int main(){
    list<int> data = ReadFile("input.txt");    
    fuel = 0;
    for (int weight : data){ //for all given weights calculate the needed fuel
        int addedFuel = -1;
        while (!addedFuel == 0){ //Keep calculating needed fuel for all the fuel that is needed.
            addedFuel = FuelNeeded(weight);
            weight = addedFuel;
            fuel = fuel + addedFuel;
        }
    }
    cout << "fuel needed: " << fuel << endl;
    return 0;
}
