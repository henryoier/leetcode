/*************************************************************************
	> File Name: 304_RangeSumQuery2D-Immutable.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 22:52:47 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        for(int i = 0; i < matrix.size(); i++){
            vector<int> curr;
            curr.push_back(0);
            for(int j = 0; j < matrix[i].size(); j++){
                curr.push_back(matrix[i][j] + *prev(curr.end()));
            }
            sum.push_back(curr);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for(int i = row1; i <= row2; i++){
            result += sum[i][col2 + 1] - sum[i][col1];
        }
        return result;
    }
private:
    vector<vector<int>> sum;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
