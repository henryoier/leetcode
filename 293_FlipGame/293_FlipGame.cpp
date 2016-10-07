/*************************************************************************
	> File Name: 293_FlipGame.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 01:25:22 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        
        if(s.length() < 2)
            return result;
        
        for(int i = 0; i < s.length() - 1; i++)
            if (s[i] == '+' && s[i + 1] == '+'){
                s[i] = '-';
                s[i + 1] = '-';
                result.push_back(s);
                s[i] = '+';
                s[i + 1] = '+';
            }
        return result;
    }
};
