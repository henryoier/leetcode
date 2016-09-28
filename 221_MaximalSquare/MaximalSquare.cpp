/*************************************************************************
	> File Name: MaximalSquare.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 28 00:40:22 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
            
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        
        int max = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] == '1'){
                    if(i == 0 || j == 0)
                        f[i][j] = 1;
                    else{
                        f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
                    }
                    if(f[i][j] > max)
                            max = f[i][j];
                    
                }
        return max * max;
    }
};
