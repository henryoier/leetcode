/*************************************************************************
	> File Name: 249_GroupShiftedStrings.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 19:15:37 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        
        for(int i = 0; i < strings.size(); i++){
            if(result.empty())
                result.push_back(vector<string>(1, strings[i]));
            else{
                bool found = false;
                for(int j = 0; j < result.size(); j++)
                    if(checkShift(result[j][0], strings[i])){
                        result[j].push_back(strings[i]);
                        found = true;
                        break;
                    }
                if(!found){
                    result.push_back(vector<string>(1, strings[i]));
                }
            }
        }
        return result;
    }
private:
    bool checkShift(string a, string b){
        if(a.length() != b.length())
            return false;
        int diff;
        for(int i = 0; i < a.length(); i++){
            if(i == 0)
                diff = (b[i] + 26 - a[i]) % 26;
            else
                if((b[i] + 26 - a[i]) % 26 != diff)
                    return false;
        }
        return true;
    }
};
