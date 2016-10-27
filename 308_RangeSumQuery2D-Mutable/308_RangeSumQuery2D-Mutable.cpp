/*************************************************************************
	> File Name: 308_RangeSumQuery2D-Mutable.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct 26 22:31:51 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return;
            
        mat = matrix;
        n = mat.size();
        m = mat[0].size();
            
        bit = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                insert(i + 1, j + 1, mat[i][j]);
    }

    void update(int row, int col, int val) {
        insert(row + 1, col + 1, val - mat[row][col]);
        mat[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        cout << query(row2 + 1, col2 + 1) << endl;
        return query(row2 + 1, col2 + 1) + query(row1, col1) - query(row2 + 1, col1) - query(row1, col2 + 1);
    }
private:
    vector<vector<int>> bit;
    vector<vector<int>> mat;
    int m, n;
    
    void insert(int x, int y, int val){
        for(int i = x; i <= n; i += (i & -i))
            for(int j = y; j <= m; j += (j & -j)){
                bit[i][j] += val;
            }
    }
    
    int query(int x, int y){
        int result = 0;
        for(int i = x; i > 0; i -= (i & -i))
            for(int j = y; j > 0; j -= (j & -j))
                result += bit[i][j];
        return result;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
