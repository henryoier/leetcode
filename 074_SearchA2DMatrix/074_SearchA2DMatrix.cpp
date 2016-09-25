/*************************************************************************
	> File Name: 074_SearchA2DMatrix.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Sep 24 23:11:38 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int head = 0, tail = matrix.size() - 1;
        while(head < tail){
            int mid = (head + tail + 1) / 2;
            if(target >= matrix[mid][0])
                head = mid;
            else
                tail = mid - 1;
        }
        
        int index = head;
        cout << index;
        head = 0;
        tail = matrix[index].size() - 1;
        
        while(head < tail){
            int mid = (head + tail + 1) / 2;
            if(target >= matrix[index][mid])
                head = mid;
            else
                tail = mid - 1;
        }
        cout << head;
        return target == matrix[index][head];
    }
};
