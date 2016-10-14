/*************************************************************************
	> File Name: 417_PacificAtlanticWaterFlow.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct 14 19:36:37 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return result;
        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<bool>> pc(n, vector<bool>(m, false));
        vector<vector<bool>> at(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++){
            if(!pc[i][0])
                dfs(i, 0, true, pc, matrix);
            if(!at[i][m - 1])
                dfs(i, m - 1, false, at, matrix);
        }
        
        for(int j = 0; j < m; j++){
            if(!pc[0][j])
                dfs(0, j, true, pc, matrix);
            if(!at[n - 1][j])
                dfs(n - 1, j, false, at, matrix);
        }
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(pc[i][j] && at[i][j])
                    result.push_back(pair<int, int>(i,j));
        
        return result;
    }
private:
    void dfs(int x, int y, bool p, vector<vector<bool>>& map, vector<vector<int>>& matrix){
        if(p){
            map[x][y] = true;
            if(x + 1 < map.size() && !map[x + 1][y] && matrix[x + 1][y] >= matrix[x][y])
                dfs(x + 1, y, p, map, matrix);
            if(y + 1 < map[0].size() && !map[x][y + 1] && matrix[x][y + 1] >= matrix[x][y])
                dfs(x, y + 1, p, map, matrix);
            if(x - 1 >= 0 && !map[x - 1][y] && matrix[x - 1][y] >= matrix[x][y])
                dfs(x - 1, y, p, map, matrix);
            if(y - 1 >= 0 && !map[x][y - 1] && matrix[x][y - 1] >= matrix[x][y])
                dfs(x, y - 1, p, map, matrix);
        } else {
            map[x][y] = true;
            if(x + 1 < map.size() && !map[x + 1][y] && matrix[x + 1][y] >= matrix[x][y])
                dfs(x + 1, y, p, map, matrix);
            if(y + 1 < map[0].size() && !map[x][y + 1] && matrix[x][y + 1] >= matrix[x][y])
                dfs(x, y + 1, p, map, matrix);
            if(x - 1 >= 0 && !map[x - 1][y] && matrix[x - 1][y] >= matrix[x][y])
                dfs(x - 1, y, p, map, matrix);
            if(y - 1 >= 0 && !map[x][y - 1] && matrix[x][y - 1] >= matrix[x][y])
                dfs(x, y - 1, p, map, matrix);
        }
    }
};
