/*************************************************************************
	> File Name: 048_RotateImage.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 23 21:28:34 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return;
        rotateImage(matrix, 0, matrix.size() - 1);
    }
private:
    void rotateImage(vector<vector<int>>& matrix, int start, int end){
        if(end <= start)
            return;
        for(int i = 0; i < end - start; i++){
            int mid = matrix[start][start + i];
            matrix[start][start + i] = matrix[end - i][start];
            matrix[end - i][start] = matrix[end][end - i];
            matrix[end][end - i] = matrix[start + i][end];
            matrix[start + i][end] = mid;
        }
        rotateImage(matrix, start + 1, end - 1);
    }
};

