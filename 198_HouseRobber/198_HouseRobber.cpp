/*************************************************************************
	> File Name: 198_HouseRobber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 26 23:06:06 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
            
        int f[nums.size()];
        for(int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1)
                f[i] = nums[i];
            else 
                if(i == nums.size() - 2)
                    f[i] = max(nums[i], f[i + 1]);
                else
                    f[i] = max(f[i + 1], nums[i] + f[i + 2]);
        }
        return f[0];
    }
};
