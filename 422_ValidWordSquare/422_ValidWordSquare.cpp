/*************************************************************************
	> File Name: 422_ValidWordSquare.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct 17 15:31:07 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if(words.size() == 0 || words[0].size() == 0)
            return true;
        int n = words.size();
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < min(i, (int)words[i].length()); j++)
                if(i >= words[j].length() || words[i][j] != words[j][i])
                    return false;
                    
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < words[i].length(); j++)
                if(i >= words[j].length() || words[i][j] != words[j][i])
                    return false;
        return true;
    }
};
