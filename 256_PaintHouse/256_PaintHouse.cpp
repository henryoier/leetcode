/*************************************************************************
	> File Name: 256_PaintHouse.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 23:51:51 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty())
            return 0;
        for(int i = 1; i < costs.size(); i++)
            for(int j = 0; j <= 2; j++){
                int minCost = INT_MAX;
                for(int k = 0; k <= 2; k++){
                    if(k != j)
                        minCost = min(minCost, costs[i - 1][k]); 
                }
                costs[i][j] += minCost;
            }
        int minCost = INT_MAX;
        for(int i = 0; i <= 2; i++)
            minCost = min(minCost, costs[costs.size() - 1][i]);
        return minCost;
    }
};
