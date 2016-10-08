/*************************************************************************
	> File Name: 251_Flatten2DVector.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 21:40:25 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        vec = vec2d;
    }

    int next() {
        col++;
        while(col >= vec[row].size()){
            col = 0;
            row++;
        }
        return vec[row][col];
    }

    bool hasNext() {
        int col_temp = col + 1, row_temp = row;
        while(row_temp < vec.size() && col_temp >= vec[row_temp].size()){
            col_temp = 0;
            row_temp += 1;
        }
        if(row_temp < vec.size())
            return true;
        else
            return false;
    }
private:
    int row = 0, col = -1;
    vector<vector<int>> vec;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
