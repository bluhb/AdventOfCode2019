#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <set>
#include <vector>

//coordinates are stored in a vector. x,y
//y=3. . . .
//y=2. . . .
//y=1. . . .
//y=0. . . .
//x= 0 1 2 3

const int Lines = 2;
const int Length = 1000;
const std::string File = "input.txt";

std::set<std::vector <int>> Coordinates1;
std::vector<std::vector<std::vector <int>>> Coordinates;
std::set<std::vector <int>> Intersections;

std::vector <int> Origin = {0,0};
std::vector <int> Current;
std::vector <int> New;

std::string Data[Lines][Length];

void readFile(std::string FileName){ //Read in the data file
    std::ifstream MyFile(FileName);
    std::string Line, T;
    int i = 0;
    if (MyFile.is_open()){
        while (! MyFile.eof()){
            Line = "";
            std::getline(MyFile, Line); //read line
            std::stringstream X(Line);
            int j = 0;
            while (std::getline(X, T, ',')){
                Data[i][j] = T;
                j++;
            }
            i++;
        }
        MyFile.close();
    }
    else {std::cout << "No file found";}
}

void add(char Dir, int Distance, int Iteration, int Step){
    Current = Coordinates[Iteration].back();
    for (int i=1; i<abs(Distance)+1; i++){
        if ((Dir == 'R') | (Dir == 'L')){
            New = {Current[0], Current[1] + i * (Distance/abs(Distance))};
        }else if ((Dir == 'U') | (Dir == 'D')){
            New = {Current[0] + i * (Distance/abs(Distance)), Current[1]};
        }

        if (Iteration > 0 && (Coordinates1.count(New) > 0)){
            New.push_back(Coordinates[Iteration].size());
            Intersections.insert(New);
            std::cout << "Intersections found at: " << New[0] << ":" << New[1] << " At: " << New[2] << std::endl;
        }else if (Iteration == 0){
            Coordinates1.insert(New);
        }
        Coordinates[Iteration].push_back(New);
    }
}

int minDist(){
    int Dist;
    int MinDist = -1;
    std::vector<int> MinIntersect(2);
    for (std::vector<int> Intersect : Intersections){
        Dist = abs(Intersect[0]) + abs(Intersect[1]);
        if ((Dist < MinDist) | (MinDist == -1)){
            MinIntersect = Intersect;
            MinDist = Dist;
        }
    }
    std::cout << "Point: " << MinIntersect[0] << ":" << MinIntersect[1] << std::endl;
    return (MinDist);
}

int minSteps(){
    int MinSteps = -1;
    
    for (std::vector<int> Intersect : Intersections){
        int Step1 = 0;
        int Step2 = 0;
        int Steps = 0;
        Step1 = Intersect.back();
        Intersect.pop_back();
        auto it = std::find(Coordinates[0].begin(), Coordinates[0].end(), Intersect);
        auto found = *it;
        std::cout << found[0] << ":"<< found[1] << " - " << Intersect[0] << ":" << Intersect[1] << std::endl;
        Step2 = it - Coordinates[0].begin();
        Steps = Step1 + Step2;
        std::cout << Step1 << " + " << Step2 << " : " << Steps << std::endl;

        if ((Steps < MinSteps) | (MinSteps == -1)){
            MinSteps = Steps;
        }

    }

    return (MinSteps);
}

int main(){
    std::string Distances;
    int Distance;
    readFile(File);
    Coordinates1.insert(Origin);
    
    std::vector<std::vector<int>> Start = {{0,0}};
    Coordinates.push_back(Start);
    Coordinates.push_back(Start);
    for (int i = 0; i < Lines; i++){
        std::cout << "Line: " << i << std::endl;
        for (int j = 0; j< Length; j++){
            std::string Temp = Data[i][j];
            if (! Temp.length()==0){
                if ((Temp[0] == 'L') | (Temp[0] == 'D')){
                    Distances = (Temp.substr(1));
                    Distance = std::stoi(Distances) * -1;
                }else{
                    Distances = (Temp.substr(1));
                    Distance = std::stoi(Distances);
                }
                add(Temp[0], Distance, i, j);
            }
        }
    }
    int MinimumDist = minDist();
    int MinimumSteps = minSteps();
    std::cout << std::endl << "Min distance: " << MinimumDist << std::endl;

    std::cout << std::endl << "Min Steps: " << MinimumSteps << std::endl;
    return 0;
}
