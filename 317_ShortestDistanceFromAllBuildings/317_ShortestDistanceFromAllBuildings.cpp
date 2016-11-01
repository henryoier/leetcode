/*************************************************************************
	> File Name: 317_ShortestDistanceFromAllBuildings.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Nov  1 17:33:34 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return -1;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 0));
        vector<vector<int>> count(n, vector<int>(m, 0));
        int b = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1){
                    b += 1;
                    vector<vector<bool>> visited(n, vector<bool>(m, false));
                    visited[i][j] = true;
                    queue<pair<int, int>> q;
                    int cur_depth = -1;
                    q.push(pair<int, int>(i, j));
                    
                    while(!q.empty()){
                        cur_depth++;
                        if(cur_depth == 0){
                            int cur_i = q.front().first;
                            int cur_j = q.front().second;
                            q.pop();
                            if(cur_i + 1 < n && !visited[cur_i + 1][cur_j] && grid[cur_i + 1][cur_j] == 0){
                                visited[cur_i + 1][cur_j] = true;
                                q.push(pair<int, int>(cur_i + 1, cur_j));
                            }
                            if(cur_i - 1 >= 0 && !visited[cur_i - 1][cur_j] && grid[cur_i - 1][cur_j] == 0){
                                visited[cur_i - 1][cur_j] = true;
                                q.push(pair<int, int>(cur_i - 1, cur_j));
                            }
                            if(cur_j + 1 < m && !visited[cur_i][cur_j + 1] && grid[cur_i][cur_j + 1] == 0){
                                visited[cur_i][cur_j + 1] = true;
                                q.push(pair<int, int>(cur_i, cur_j + 1));
                            }
                            if(cur_j - 1 >= 0 && !visited[cur_i][cur_j - 1] && grid[cur_i][cur_j - 1] == 0){
                                visited[cur_i][cur_j - 1] = true;
                                q.push(pair<int, int>(cur_i, cur_j - 1));
                            }
                        } else {
                            int t = q.size();
                            for(int k = 0; k < t; k++){
                                int cur_i = q.front().first;
                                int cur_j = q.front().second;
                                q.pop();
                                distance[cur_i][cur_j] += cur_depth;
                                count[cur_i][cur_j] += 1;
                                if(cur_i + 1 < n && !visited[cur_i + 1][cur_j] && grid[cur_i + 1][cur_j] == 0){
                                    visited[cur_i + 1][cur_j] = true;
                                    q.push(pair<int, int>(cur_i + 1, cur_j));
                                }
                                if(cur_i - 1 >= 0 && !visited[cur_i - 1][cur_j] && grid[cur_i - 1][cur_j] == 0){
                                    visited[cur_i - 1][cur_j] = true;
                                    q.push(pair<int, int>(cur_i - 1, cur_j));
                                }
                                if(cur_j + 1 < m && !visited[cur_i][cur_j + 1] && grid[cur_i][cur_j + 1] == 0){
                                    visited[cur_i][cur_j + 1] = true;
                                    q.push(pair<int, int>(cur_i, cur_j + 1));
                                }
                                if(cur_j - 1 >= 0 && !visited[cur_i][cur_j - 1] && grid[cur_i][cur_j - 1] == 0){
                                    visited[cur_i][cur_j - 1] = true;
                                    q.push(pair<int, int>(cur_i, cur_j - 1));
                                }
                            }
                        }
                    }
                }
                int min_dist = INT_MAX;
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < m; j++)
                        if(grid[i][j] == 0 && count[i][j] == b)
                            min_dist = min(min_dist, distance[i][j]);
                            
                if(min_dist == INT_MAX)
                    return -1;
                else
                    return min_dist;
    }
};
