/*************************************************************************
	> File Name: 174_DungeonGame.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 26 21:49:18 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        
        for(int i = m - 1; i >= 0; i--)
            for(int j = n - 1; j >= 0; j--){
                if(i == m - 1 && j == n - 1){
                    if(dungeon[i][j] < 0)
                        f[i][j] = 1 - dungeon[i][j];
                    else
                        f[i][j] = 1;
                } else if(i == m - 1){
                    f[i][j] = max(1, f[i][j + 1] - dungeon[i][j]);
                } else if(j == n - 1)
                    f[i][j] = max(1, f[i + 1][j] - dungeon[i][j]);
                else
                    f[i][j] = max(1, min(f[i + 1][j], f[i][j + 1]) - dungeon[i][j]);
            }
        return f[0][0];
    }
};
