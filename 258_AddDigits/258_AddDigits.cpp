/*************************************************************************
	> File Name: 258_AddDigits.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 22:38:11 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;    
    }
};
