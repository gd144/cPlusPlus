#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <tuple>
#include "Allocator.h"
using namespace std;

int main (int x, char *argv[]){
    string staffTxt    = "";
    string projectsTxt = "";
    string studentsTxt = "";
    try{
        staffTxt    = argv[1];
        projectsTxt = argv[2];
        studentsTxt = argv[3];
    }
    catch(exception e){
        cout << "Incorrect arguments" << endl;
    }
    ifstream inputFile;
    inputFile.open(staffTxt.c_str());


    const char delimiter = ' ';
    string staffText = "";
    int effort = -1;
    vector<tuple<string, int>> staff;

    getline(inputFile, staffText, delimiter);
    inputFile >> effort;
    inputFile.ignore(INT16_MAX, '\n');
    while (inputFile){
        staff.push_back(make_tuple(staffText, effort));
        getline(inputFile, staffText, delimiter);
        inputFile >> effort;
        inputFile.ignore(INT16_MAX, '\n');
    }
    inputFile.close();
    inputFile.clear();
    inputFile.open(projectsTxt.c_str());

    int projectNo = -1;
    string projectStaff = "";
    int projectAvalible = -1;
    string projectName = "";
    vector<tuple<int, string, int, string>> projects;

    inputFile >> projectNo;
    inputFile.ignore(INT16_MAX, ' ');
    getline(inputFile, projectStaff, delimiter);
    inputFile >> projectAvalible;
    inputFile.ignore(INT16_MAX, ' ');
    getline(inputFile, projectName, '\n');
    while (inputFile){
        projects.push_back(make_tuple(projectNo, projectStaff, projectAvalible, projectName)); 
        inputFile >> projectNo;
        inputFile.ignore(INT16_MAX, ' ');
        getline(inputFile, projectStaff, delimiter);
        inputFile >> projectAvalible;
        inputFile.ignore(INT16_MAX, ' ');
        getline(inputFile, projectName, '\n');
    }
    inputFile.close();
    inputFile.clear();
    inputFile.open(studentsTxt.c_str());

    string stuName = "";
    int choice1 = -1;
    int choice2 = -1;
    int choice3 = -1;
    int choice4 = -1;
    vector<tuple<string, int, int, int, int>> students;

    getline(inputFile, stuName, delimiter);
    inputFile >> choice1;
    inputFile >> choice2;
    inputFile >> choice3;
    inputFile >> choice4;
    inputFile.ignore(INT16_MAX, '\n');

    while(inputFile){
        students.push_back(make_tuple(stuName,choice1,choice2,choice3,choice4));
        getline(inputFile, stuName, delimiter);
        inputFile >> choice1;
        inputFile >> choice2;
        inputFile >> choice3;
        inputFile >> choice4;
        inputFile.ignore(INT16_MAX, '\n');
    }
    inputFile.close();
    inputFile.clear();

    Allocator allocate = Allocator(staff, projects, students);
    vector<tuple<string,int>> allocation = allocate.allocate();
    ofstream finalAllocation("alloc.txt");
    for(int i = 0; i < allocation.size(); i++){
        cout << get<0>(allocation[i]) << " " << get<1>(allocation[i]) << endl;
        finalAllocation << get<0>(allocation[i]) << " " << get<1>(allocation[i]) << endl;
    }
    finalAllocation << allocate.getScore() << endl;
    finalAllocation.close();
}