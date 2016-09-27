/*************************************************************************
	> File Name: 189_RotateArray.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 26 22:47:31 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        
        nums.insert(nums.begin(), nums.end() - k, nums.end());
        nums.erase(nums.end() - k, nums.end());
        
    }
};
