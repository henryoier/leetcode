/*************************************************************************
	> File Name: 200_NumberOfIslands.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 26 23:34:51 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
            
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    count++;
                    floodfill(grid, i, j);
                }   
            }
        return count;
    }
private:
    void floodfill(vector<vector<char>>& grid, int i , int j){
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != '1')
            return;
            
        grid[i][j] = '0';
        
        floodfill(grid, i + 1, j);
        floodfill(grid, i - 1, j);
        floodfill(grid, i, j + 1);
        floodfill(grid, i, j - 1);
    }
};

