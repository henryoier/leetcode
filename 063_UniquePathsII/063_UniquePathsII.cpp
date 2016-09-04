/*************************************************************************
	> File Name: 063_UniquePathsII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Sep  3 21:43:28 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        long f[m][n];
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(obstacleGrid[i][j] == 1)
                    f[i][j] = 0;
                else
                    if(i == 0 && j == 0)
                        f[i][j] = 1;
                    else
                        if(i == 0)
                            f[i][j] = f[i][j - 1];
                        else
                            if(j == 0)
                                f[i][j] = f[i - 1][j];
                            else
                                f[i][j] = f[i - 1][j] + f[i][j - 1];

        return f[m - 1][n - 1];
    }
};

int main(){
    return 0;
}
