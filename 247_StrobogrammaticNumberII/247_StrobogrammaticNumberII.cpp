/*************************************************************************
	> File Name: 247_StrobogrammaticNumberII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 16:57:58 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return getStro(n, n); 
    }
private:
    vector<string> getStro(int n, int init_n){
        if(n == 0)
            return vector<string>({""});
        else if(n == 1)
            return vector<string>({"0", "1", "8"});
        else{
            vector<string> temp = getStro(n - 2, init_n);
            vector<string> result;
            for(auto i:temp){
                if(n != init_n)
                    result.push_back("0" + i + "0");
                result.push_back("1" + i + "1");
                result.push_back("6" + i + "9");
                result.push_back("8" + i + "8");
                result.push_back("9" + i + "6");
            }
            return result;
        }
    }
};
