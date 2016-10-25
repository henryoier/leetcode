/*************************************************************************
	> File Name: 388_LongestAbsoluteFilePath.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct 25 11:08:15 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream in(input);
        int maxLength = 0;
        vector<int> dirLength(input.length());
        
        string cur;
        while(getline(in, cur)){
            string curDir = cur;
            while(curDir.find('\t') != string::npos)
                curDir.replace(curDir.find('\t'), 1, "");
            int curDepth = cur.length() - curDir.length();
            dirLength[curDepth] = curDir.length();
            if(curDir.find('.') != string::npos){
                int temp = 0;
                for(int i = 0; i <= curDepth; i++)
                    temp += dirLength[i];
                maxLength = max(maxLength, temp + curDepth);
            }
        }
        return maxLength;
    }
};
