/*************************************************************************
	> File Name: 044_WildcardMatching.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Nov  3 15:49:37 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> f(2, vector<bool>(m + 1, false));
        
        f[0][0] = true;
        for(int i = 0; i < m; i++)
            if(p[i] == '*')
                f[0][i + 1] = true;
            else
                break;
                
    
        for(int i = 1; i <= n; i++){
            f[i % 2][0] = false;
            for(int j = 1; j <= m; j++)
                if(p[j - 1] == '*'){
                    f[i % 2][j] = f[i % 2][j - 1] || f[(i + 1) % 2][j];
                } else if(p[j - 1] == '?' || s[i - 1] == p[j - 1])
                    f[i % 2][j] = f[(i + 1) % 2][j - 1];
                else
                    f[i % 2][j] = false;
        }
                    
        return f[n % 2][m];
    }
};
