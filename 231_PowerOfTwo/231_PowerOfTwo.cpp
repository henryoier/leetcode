/*************************************************************************
	> File Name: 231_PowerOfTwo.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 00:06:53 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
            
        while(!(n & 1)) n = n >> 1;
        return n==1;
    }
};
