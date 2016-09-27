/*************************************************************************
	> File Name: 190_ReverseBits.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 26 22:53:28 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; i++){
            result = result * 2 + n % 2;
            n = n / 2;
        }   
        return result;
    }
};
