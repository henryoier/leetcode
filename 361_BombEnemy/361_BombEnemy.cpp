/*************************************************************************
	> File Name: 361_BombEnemy.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct 10 14:04:20 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
            
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> left(n, vector<int>(m ,0));
        vector<vector<int>> right(n, vector<int>(m ,0));
        vector<vector<int>> up(n, vector<int>(m ,0));
        vector<vector<int>> down(n, vector<int>(m ,0));
        
        
        int killMax = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j == 0){
                    left[i][j] = 0;
                    right[i][m - 1 - j] = 0;
                } else {
                    if(grid[i][j - 1] == 'E'){
                        left[i][j] = left[i][j - 1] + 1;
                    } else if(grid[i][j - 1] == 'W'){
                        left[i][j] == 0;
                    } else left[i][j] = left[i][j - 1];
                    
                    if(grid[i][m - j] == 'E'){
                        right[i][m - 1 - j] = right[i][m - j] + 1;
                    } else if(grid[i][m - j] == 'W'){
                        right[i][m - 1 - j] == 0;
                    } else right[i][m - 1 - j] = right[i][m - j];
                }
            }
        }
        
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(i == 0){
                    up[i][j] = 0;
                    down[n - i - 1][j] = 0;
                } else {
                    if(grid[i - 1][j] == 'E'){
                        up[i][j] = up[i - 1][j] + 1;
                    } else if(grid[i - 1][j] == 'W'){
                        up[i][j] == 0;
                    } else up[i][j] = up[i - 1][j];
                    
                    if(grid[n - i][j] == 'E'){
                        down[n - 1 - i][j] = down[n - i][j] + 1;
                    } else if(grid[n - i][j] == 'W'){
                        down[n - 1 - i][j] == 0;
                    } else down[n - 1 - i][j] = down[n - i][j];
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != '0')
                    continue;
                int cur = 0;
                cur = up[i][j] + down[i][j] + left[i][j] + right[i][j];
                killMax = max(killMax, cur);
            }
        }
        
        return killMax;
    }
};
