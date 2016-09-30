/*************************************************************************
	> File Name: 263_UglyNumber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 23:09:42 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num < 1)
            return false;
            
        while(num % 2 == 0){
            num = num / 2;
        }    
        while(num % 3 == 0){
            num = num / 3;
        }
        while(num % 5 == 0){
            num = num / 5;
        }
        if(num == 1)
            return true;
        else
            return false;
    }
};
