/*************************************************************************
	> File Name: 070_ClimbingStairs.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Sep  4 19:42:11 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        long f[n];
        f[0] = 1;
        f[1] = 2;
        for(int i = 2; i < n; i++)
            f[i] = f[i - 1] + f[i - 2];

        return f[n - 1];
    }
};

int main() {
    Solution newSolution;

    cout << newSolution.climbStairs(5) << endl;

    return 0;
}
