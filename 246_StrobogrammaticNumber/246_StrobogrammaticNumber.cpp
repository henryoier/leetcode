/*************************************************************************
	> File Name: 246_StrobogrammaticNumber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 16:48:10 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        for(int i = 0; i <= (num.length() - 1) / 2; i++)
            if(!checkStrobogrammatic(num[i], num[num.length() - 1 - i]))
                return false;
        return true;
    }
private:
    bool checkStrobogrammatic(char a, char b){
        if(a == b){
            if(a == '1' || a == '8' || a == '0'){
                return true;
            } else
                return false;
        } else 
            if(a == '6' && b == '9' || a == '9' && b == '6')
                return true;
            else    
                return false;
    }
};
