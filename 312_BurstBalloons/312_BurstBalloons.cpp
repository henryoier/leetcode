/*************************************************************************
	> File Name: 312_BurstBalloons.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Nov  3 19:40:01 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty())
            return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> f(nums.size(), vector<int>(nums.size(), 0));
        
        for(int len = 1; len <= nums.size() - 2; len++)
            for(int start = 1; start + len < nums.size(); start++){
                int end = start + len - 1;
                for(int k = start; k <= end; k++){
                    f[start][end] = max(f[start][end], f[start][k - 1] + f[k + 1][end] + nums[k] * nums[start - 1] * nums[end + 1]);
                }
            }
        return f[1][nums.size() - 2];
    }
};
