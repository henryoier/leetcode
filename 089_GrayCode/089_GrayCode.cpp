/*************************************************************************
	> File Name: 089_GrayCode.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Sep 25 20:00:57 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0)
            return vector<int>(1, 0);
        
        vector<int> result1;
        result1 = grayCode(n - 1);
        vector<int> result = result1;
        for(int i = result1.size() - 1; i >=0; i--)
            result.push_back((1 << (n - 1)) + result1[i]);
                    
        return result;
        
    }
};
