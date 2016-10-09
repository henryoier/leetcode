/*************************************************************************
	> File Name: 276_PaintFence.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  8 21:25:02 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0)
            return 0;
        int f[n];
        f[0] = k;
        for(int i = 1; i < n; i++)
            if(i == 1)
                f[1] = k * k;
            else
                f[i] = (k - 1) * f[i - 1] + (k - 1) * f[i - 2];
        return f[n - 1];
    }
};
