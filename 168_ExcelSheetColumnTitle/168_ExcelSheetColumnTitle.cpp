/*************************************************************************
	> File Name: 168_ExcelSheetColumnTitle.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 26 16:15:41 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while(n > 0){
            result = (char)((n - 1) % 26 + 'A') + result;
            n = (n - 1) / 26;
        }
        return result;
    }
};

