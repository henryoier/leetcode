/*************************************************************************
	> File Name: 201_BitwiseANDOfNumbersRange.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 26 23:56:04 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (n > m) n &= (n-1);
        return n;
    }
};
