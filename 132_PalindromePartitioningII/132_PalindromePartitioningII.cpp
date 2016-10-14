/*************************************************************************
	> File Name: 132_PalindromePartitioningII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct 14 18:17:10 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        
        vector<int> minCut(n, INT_MAX);
        vector<vector<bool>> palin(n, vector<bool>(n, false));
        
        minCut[0] = 0;
        for(int end = 1; end < n; end++)
            for(int start = end; start >= 0; start--){
                if(s[start] == s[end] && (end - start < 2 || palin[start + 1][end - 1])){
                    palin[start][end] = true;
                    if(start == 0)
                        minCut[end] = 0;
                    else
                        minCut[end] = min(minCut[end], minCut[start - 1] + 1); 
                }
            }
        return minCut[n - 1];
    }
};
