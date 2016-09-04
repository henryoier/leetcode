/*************************************************************************
	> File Name: 064_MinimumPathSum.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Sep  4 18:20:17 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int f[m][n];

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(i ==  0 && j = 0)
                    f[i][j] = grid[i][j];
                else
                    if(i == 0)
                        f[i][j] = f[i][j - 1] + grid[i][j];
                    else
                        if(j == 0)
                            f[i][j] = f[i - 1][j] + grid[i][j];
                        else
                            f[i][j] = grid[i][j] + (f[i - 1][j] < f[i][j - 1]?f[i - 1][j]:f[i][j-1]);

        return f[m - 1][n - 1];
    }
};

int main() {

}
