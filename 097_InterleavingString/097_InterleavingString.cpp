/*************************************************************************
	> File Name: 097_InterleavingString.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 19 21:19:00 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length();
        if(n == 0)
            return s2 == s3;
        if(m == 0)
            return s1 == s3;
        if(s3.length() == 0 || m + n != s3.length())
            return false;
            
        bool f[n + 1][m + 1];
        f[0][0] = true;
        
        for(int i = 1; i <= n; i++)
            f[i][0] = s1[i - 1] == s3[i - 1]?f[i - 1][0]:false;
        for(int j = 1; j <=m; j++)
            f[0][j] = s2[j - 1] == s3[j - 1]?f[0][j - 1]:false;
            
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
                    f[i][j] = f[i - 1][j] || f[i][j - 1];
                else if (s1[i - 1] == s3[i + j - 1])
                        f[i][j] = f[i - 1][j];
                else if (s2[j - 1] == s3[i + j - 1])
                        f[i][j] = f[i][j - 1];
                    else
                        f[i][j] = false;
            }
        return f[n][m];
    }
};

int main () {
    return 0;
}
