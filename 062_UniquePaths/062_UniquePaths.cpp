/*************************************************************************
	> File Name: 062_UniquePaths.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Sep  3 21:36:38 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long f[m][n];
        for(int i = 0; i < m; i++)
            f[i][0] = 1;
        for(int i = 0; i < n; i++)
            f[0][i] = 1;

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                f[i][j] = f[i - 1][j] + f[i][j - 1];
        
        return f[m - 1][n - 1];
    }
};

int main() {
    Solution newSolution;
    cout << newSolution.uniquePaths(3,3) << endl;

    return 0;
}
