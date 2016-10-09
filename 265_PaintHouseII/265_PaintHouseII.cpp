/*************************************************************************
	> File Name: 265_PaintHouseII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  8 23:17:56 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0)
            return 0;
        int k = costs[0].size();
        
        int m1_idx, m1, m2;
        for(int i = 0; i < n; i++){
            int m1_cur = INT_MAX, m1_cur_idx, m2_cur = INT_MAX;
            for(int j = 0; j < k; j++)
                if(i == 0)
                    if(costs[i][j] < m1_cur){
                        m2_cur = m1_cur;
                        m1_cur = costs[i][j];
                        m1_cur_idx = j;
                    } else if(costs[i][j] < m2_cur){
                        m2_cur = costs[i][j];
                    } else {}
                else 
                    if(j == m1_idx){
                        costs[i][j] += m2;
                        if(costs[i][j] < m1_cur){
                            m2_cur = m1_cur;
                            m1_cur = costs[i][j];
                            m1_cur_idx = j;
                        } else if(costs[i][j] < m2_cur){
                            m2_cur = costs[i][j];
                        } else {
                        }
                    } else {
                        costs[i][j] += m1;
                        if(costs[i][j] < m1_cur){
                            m2_cur = m1_cur;
                            m1_cur = costs[i][j];
                            m1_cur_idx = j;
                        } else if(costs[i][j] < m2_cur){
                            m2_cur = costs[i][j];
                        }
                }
                m1 = m1_cur;
                m1_idx = m1_cur_idx;
                m2 = m2_cur;
        }   
        int result = INT_MAX;
        for(int j = 0; j < k; j++)
            result  = min(result, costs[n - 1][j]);
        
        return result;
    }
};
