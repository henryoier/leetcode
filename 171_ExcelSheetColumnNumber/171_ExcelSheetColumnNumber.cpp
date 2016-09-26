/*************************************************************************
	> File Name: 171_ExcelSheetColumnNumber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 26 16:32:19 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(auto i:s){
            result = result*26 + (i - 'A') + 1;
        }    
        return result;
    }
};
