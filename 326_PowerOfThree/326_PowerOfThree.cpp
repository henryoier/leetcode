/*************************************************************************
	> File Name: 326_PowerOfThree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct  3 23:24:17 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        double temp = log10(n) / log10(3);
        return n <= 0?false:floor(temp) == temp;
    }
};
