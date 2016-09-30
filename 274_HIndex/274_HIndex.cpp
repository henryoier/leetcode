/*************************************************************************
	> File Name: 274_HIndex.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 10:30:51 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        
        for(int i = citations.size() - 1; i >= 0; i--)
            if(citations[i] >= (i + 1))
                return i + 1;
        return 0;
    }
};

