/*************************************************************************
	> File Name: 279_PerfectSquare.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 11:30:41 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int f[n + 1];
        f[0] = 0;
        for(int i = 1; i <= n; i++){
            f[i] = INT_MAX;
            for(int k = 1; k * k <= i; k++){
                if(f[i - k*k] + 1 < f[i])
                    f[i] = f[i - k*k] + 1;
            }
        }
        return f[n];
    }
};
