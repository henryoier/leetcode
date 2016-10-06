/*************************************************************************
	> File Name: 343_IntegerBreak.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct  5 21:41:38 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        int f[n + 1];
        f[1] = 1;
        for(int i = 2; i <= n; i++){
            f[i] = 0;
            for(int k = 1; k <= (i + 1) / 2; k++){
                f[i] = max(max(k, f[k]) * max(i-k, f[i - k]), f[i]);
            }
        }    
        return f[n];
    }
};
