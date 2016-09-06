/*************************************************************************
	> File Name: 073_SetMatrixZeroes.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep  6 19:25:43 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> column, row;

        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j] == 0){
                    row.insert(i);
                    column.insert(j);
                }
        for(auto i = row.begin(); i != row.end(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                matrix[*i][j] = 0;
        
        for(auto i = column.begin(); i != column.end(); i++)
            for(int j = 0; j < matrix.size(); j++)
                matrix[j][*i] = 0;
    }
};

int main() {
    return 0;
}
