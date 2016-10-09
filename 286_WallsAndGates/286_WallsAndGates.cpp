/*************************************************************************
	> File Name: 286_WallsAndGates.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  8 23:51:21 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0 || rooms[0].size() == 0)
            return;
        for(int i = 0; i < rooms.size(); i++)
            for(int j = 0; j < rooms[0].size(); j++)
                if(rooms[i][j] == 0)
                    dfs(i,j,rooms, 0);
    }
private:
    void dfs(int x, int y, vector<vector<int>>& rooms, int step){
        if(x < 0 || y < 0 || x >= rooms.size() || y >= rooms[0].size() || rooms[x][y] == -1)
            return;
        if(step <= rooms[x][y]){
            rooms[x][y] = step;
            dfs(x + 1, y, rooms, step + 1);
            dfs(x - 1, y, rooms, step + 1);
            dfs(x, y + 1, rooms, step + 1);
            dfs(x, y - 1, rooms, step + 1);
        }
    }
};
