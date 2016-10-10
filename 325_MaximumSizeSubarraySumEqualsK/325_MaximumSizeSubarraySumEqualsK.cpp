/*************************************************************************
	> File Name: 325_MaximumSizeSubarraySumEqualsK.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  9 23:13:37 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sum;
        sum[0] = 0;
        int total = 0;
        int maxLength = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            if(sum.count(total - k))
                if(i + 1 - sum[total - k] > maxLength)
                    maxLength = i + 1 - sum[total - k];
            if(!sum.count(total))
                sum[total] = i + 1;
        }
        
        if(maxLength == INT_MIN)
            return 0;
        else
            return maxLength;
    }
};
