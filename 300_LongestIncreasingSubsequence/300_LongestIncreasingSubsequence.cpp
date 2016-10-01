/*************************************************************************
	> File Name: 300_LongestIncreasingSubsequence.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 21:57:56 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max = 0;
        int f[nums.size()];
        
        for(int i = 0; i < nums.size(); i++){
            f[i] = 1;
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] > nums[j] && f[j] + 1 > f[i])
                    f[i] = f[j] + 1;
            }
            if(f[i] > max)
                max = f[i];
        }
        
        return max;
    }
};
