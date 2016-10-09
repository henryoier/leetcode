/*************************************************************************
	> File Name: 296_BestMeetingPoint.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  9 15:27:48 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int n = grid.size(), m = grid[0].size();
        
        unordered_map<int, int> col;
        unordered_map<int, int> row;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1){
                    col[j]++;
                    row[i]++;
                }
                
        int minRowDist = INT_MAX, minColDist = INT_MAX;
        for(int i = 0; i < n; i++){
            int cur = calDist(i, row);   
            if(cur < minRowDist)
                minRowDist = cur;
        }
        for(int i = 0; i < m; i++){
            int cur = calDist(i, col);   
            if(cur < minColDist)
                minColDist = cur;
        }
        
        return minRowDist + minColDist;
    }
private:
    int calDist(int x, unordered_map<int, int> home){
        int result = 0;
        for(auto i:home){
            result += abs(i.first - x) * i.second;
        }
        return result;
    }
};
