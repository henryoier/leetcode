/*************************************************************************
	> File Name: 240_SearchA2DMatrixII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct 31 21:06:10 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int n = matrix.size(), m = matrix[0].size();
        
        int head = 0, tail = n;
        while(head < tail){
            int mid = head + (tail - head) / 2;
            if(matrix[mid][m - 1] < target)
                head = mid + 1;
            else
                tail = mid;
        }
        int tail_start = head;
        
        head = 0, tail = n;
        while(head < tail){
            int mid = head + (tail - head) / 2;
            if(matrix[mid][0] > target)
                tail = mid;
            else
                head = mid + 1;
        }
        int tail_end = head;
        cout << tail_start <<  ' ' << tail_end << endl;
        
        for(int i = tail_start; i < tail_end; i++){
            if(matrix[i][0] > target || matrix[i][m - 1] < target)
                continue;
            head = 0, tail = m;
            while(head <= tail){
                int mid = head + (tail - head) / 2;
                if(matrix[i][mid] > target)
                    tail = mid - 1;
                else if(matrix[i][mid] < target)
                    head = mid + 1;
                else
                    return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0, c = matrix[0].size() - 1;
        while(r < matrix.size() && c >= 0){
            if(target < matrix[r][c])
                c--;
            else if(target > matrix[r][c])
                r++;
            else
                return true;
        }
        return false;
    }
};
