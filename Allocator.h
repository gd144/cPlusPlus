#include <vector>
#include <tuple>
#include <string>
#include <iostream>
using namespace std;

class Allocator {
    public:
        Allocator();

        Allocator(vector<tuple<string, int>> staffVec, vector<tuple<int, string, int, string>> proVec, vector<tuple<string, int, int, int, int>> stuVec){
            for(int i = 0; i < staffVec.size(); i++){
                staff.push_back(staffVec[i]);
            }
            for(int i = 0; i < proVec.size(); i++){
                projects.push_back(proVec[i]);
            }
            for(int i = 0; i < stuVec.size(); i++){
                students.push_back(stuVec[i]);
            }
        }

        vector<tuple<string, int>> allocate(){
            int temp = -1;
            bool allocated = false;
            string projectStaff = "";
            for(int i = 0; i < students.size(); i++){
                allocated = false;
                temp = get<1>(students[i]);
                for(int j = 0; j < projects.size(); j++){
                    if(get<0>(projects[j]) == temp && get<2>(projects[j]) > 0){
                        get<2>(projects[j]) = get<2>(projects[j]) - 1;
                        cout << get<2>(projects[j]) << endl;
                        projectStaff = get<1>(projects[j]);
                        break;
                    }
                }
                for(int k = 0; k < staff.size(); k++){
                    if(get<0>(staff[k]) == projectStaff && get<1>(staff[k]) > 0){
                        get<1>(staff[k]) = get<1>(staff[k]) - 1;
                        allocation.push_back(make_tuple(get<0>(students[i]),temp));
                        allocated = true;
                        projectStaff = "";
                        break;
                    }
                }
                if (allocated == false){ 
                    temp = get<2>(students[i]);
                    for(int j = 0; j < projects.size(); j++){
                        if(get<0>(projects[j]) == temp && get<2>(projects[j]) > 0){
                            get<2>(projects[j]) = get<2>(projects[j]) - 1;
                            projectStaff = get<1>(projects[j]);
                            break;
                        }
                    }
                    for(int k = 0; k < staff.size(); k++){
                        if(get<0>(staff[k]) == projectStaff && get<1>(staff[k]) > 0){
                            get<1>(staff[k]) = get<1>(staff[k]) - 1;
                            allocation.push_back(make_tuple(get<0>(students[i]),temp));
                            allocated = true;
                            projectStaff = "";
                            break;
                        }
                    }
                }
                if (allocated == false){ 
                    temp = get<3>(students[i]);
                    for(int j = 0; j < projects.size(); j++){
                        if(get<0>(projects[j]) == temp && get<2>(projects[j]) > 0){
                            get<2>(projects[j]) = get<2>(projects[j]) - 1;
                            projectStaff = get<1>(projects[j]);
                            break;
                        }
                    }
                    for(int k = 0; k < staff.size(); k++){
                        if(get<0>(staff[k]) == projectStaff && get<1>(staff[k]) > 0){
                            get<1>(staff[k]) = get<1>(staff[k]) - 1;
                            allocation.push_back(make_tuple(get<0>(students[i]),temp));
                            allocated = true;
                            projectStaff = "";
                            break;
                        }
                    }
                }
                if (allocated == false){ 
                    temp = get<4>(students[i]);
                    for(int j = 0; j < projects.size(); j++){
                        if(get<0>(projects[j]) == temp && get<2>(projects[j]) > 0){
                            get<2>(projects[j]) = get<2>(projects[j]) - 1;
                            projectStaff = get<1>(projects[j]);
                            break;
                        }
                    }
                    for(int k = 0; k < staff.size(); k++){
                        if(get<0>(staff[k]) == projectStaff && get<1>(staff[k]) > 0){
                            get<1>(staff[k]) = get<1>(staff[k]) - 1;
                            allocation.push_back(make_tuple(get<0>(students[i]),temp));
                            allocated = true;
                            projectStaff = "";
                            break;
                        }
                    }
                }
                if(allocated == false){
                    allocation.push_back(make_tuple(get<0>(students[i]), 0));
                }
            }
            return allocation;
        }

        int getScore(){
            score = 0;
            string temp = "";
            for(int i = 0; i < allocation.size(); i++){
                temp = get<0>(allocation[i]);
                for (int j = 0; j < students.size(); j++){
                    if(get<0>(students[j]) == temp){
                        if(get<1>(students[j]) == get<1>(allocation[i])){
                            score = score + 4;
                        }
                        else if(get<2>(students[j]) == get<1>(allocation[i])){
                            score = score + 3;
                        }
                        else if(get<3>(students[j]) == get<1>(allocation[i])){
                            score = score + 2;
                        }
                        else if(get<4>(students[j]) == get<1>(allocation[i])){
                            score = score + 1;
                        }
                    }
                }
            }
            return score;
        }
        
    private:
        vector<tuple<string, int>> staff;
        vector<tuple<int, string, int, string>> projects;
        vector<tuple<string, int, int, int, int>> students;
        vector<tuple<string, int>> allocation;
        int score;
};