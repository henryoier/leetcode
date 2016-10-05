/*************************************************************************
	> File Name: 342_PowerOfFour.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct  4 21:48:03 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 1)
            return false;
            
        double a = log10(num) / log10(4);
        return a == floor(a);  
    }
};
