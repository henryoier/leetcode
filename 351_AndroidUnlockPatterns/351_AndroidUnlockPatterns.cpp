/*************************************************************************
	> File Name: 351_AndroidUnlockPatterns.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct 20 22:35:39 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> path(10, vector<int>(10, 0));
        
        path[1][3] = 2;
        path[3][9] = 6;
        path[7][9] = 8;
        path[1][7] = 4;
        path[2][8] = 5;
        path[4][6] = 5;
        path[1][9] = 5;
        path[3][7] = 5;
        
        int result = 0;
        
        for(int len = m; len <= n; len++){
            vector<bool> visited(10, false);
            result += dfs(1, len, path, visited) * 4;
            result += dfs(2, len, path, visited) * 4;
            result += dfs(5, len, path, visited);
        }
        
        return result;
    }
private:
    int dfs(int pos, int len, vector<vector<int>>& path, vector<bool>& visited){
        if(len == 1)
            return 1;
        
        int res = 0;
        visited[pos] = true;
        for(int next = 1; next < 10; next++){
            if(next == pos || visited[next])
                continue;
            if(path[min(next, pos)][max(next, pos)] == 0)
                res += dfs(next, len - 1, path, visited);
            else
                if(visited[path[min(next, pos)][max(next, pos)]])
                    res += dfs(next, len - 1, path, visited);
        }
        visited[pos] =  false;
        
        return res;
    }
};
