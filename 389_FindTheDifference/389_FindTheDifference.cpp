/*************************************************************************
	> File Name: 389_FindTheDifference.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  1 22:07:41 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        auto i = s.begin(), j = t.begin();
        
        while(*(i++) == *(j++));
        
        j--;
        
        return *j;
    }
};
