/*************************************************************************
	> File Name: 396_RotateFunction.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Sep 10 21:34:51 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size(), F = 0, sum = 0, max = INT_MIN;
        for(int i = 0; i < n; i++){
            F += A[i] * i;
            sum += A[i];
        }
        max = F;
        for(int i = n - 1; i > 0; i--){
            F = F + sum - n * A[i];
            if(F > max)
                max = F;
        }
        
        return max;
    }
};
