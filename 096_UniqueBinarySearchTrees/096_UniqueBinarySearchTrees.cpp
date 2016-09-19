/*************************************************************************
	> File Name: 096_UniqueBinarySearchTrees.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 19 17:07:02 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int f[n + 1];
        fill(f, f + n + 1, 0);
        if(n == 0)
            return 0;
        f[0] = 1;
        f[1] = 1;
        for(int i = 2; i<= n; i++)
            for(int root = 1; root <= i; root++){
                f[i] += f[root - 1] * f[i - root];
            }
        return f[n];
    }
};

int main() {
    return 0;
}
