/*************************************************************************
	> File Name: 191_NumberOf1Bits.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 26 22:56:37 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n > 0){
            if(n % 2 == 1)
                result++;
            n = n / 2;
        }    
        return result;
    }
};
