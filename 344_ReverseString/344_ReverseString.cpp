/*************************************************************************
	> File Name: 344_ReverseString.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct  4 23:36:23 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        if(s.length() <= 1)
            return s;
            
        for(int i = 0; i <= (s.length() - 1) / 2; i++)
            swap(s[i], s[s.length() -1 - i]);
        return s;
    }
};
