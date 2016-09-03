/*************************************************************************
	> File Name: 054_SpiralMatrix.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep  2 19:57:59 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0)
            return result;
        result = spiralMatrix(0,0,matrix.size() - 1, matrix[0].size() - 1, matrix);
        return result;
    }
private:
    vector<int> spiralMatrix(int x1, int y1, int x2, int y2, vector<vector<int>> matrix){
        vector<int> resultLeft, resultRight;
        
        if(x1 > x2 || y1 > y2)
            return resultLeft;

        if(x1 == x2 && y1 == y2){
            resultLeft.push_back(matrix[x1][y1]);
            return resultLeft;
        }

        if(x1 == x2){
            for(int i = y1; i <= y2; i++)
                resultLeft.push_back(matrix[x1][i]);
            return resultLeft;
        }

        if(y1 == y2){
            for(int i = x1; i <= x2; i++)
                resultLeft.push_back(matrix[i][y1]);
            return resultLeft;
        }

        for(int i = y1; i < y2; i++)
            resultLeft.push_back(matrix[x1][i]);
        for(int i = x1; i < x2; i++)
            resultLeft.push_back(matrix[i][y2]);    
        for(int i = y2; i > y1; i--)
            resultLeft.push_back(matrix[x2][i]);
        for(int i = x2; i > x1; i--)
            resultLeft.push_back(matrix[i][y1]);
        
        resultRight = spiralMatrix(x1 + 1, y1 + 1, x2 - 1, y2 - 1, matrix);

        resultLeft.insert(resultLeft.end(), resultRight.begin(), resultRight.end());
        
        return resultLeft;
    }
};

int main() {

}
