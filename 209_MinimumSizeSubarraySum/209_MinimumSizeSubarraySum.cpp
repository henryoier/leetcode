/*************************************************************************
	> File Name: 209_MinimumSizeSubarraySum.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 27 13:47:21 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int head = 0, tail = 0, sum = 0, min = INT_MAX;
        while(tail < nums.size()){
            sum += nums[tail++];
            if(sum >= s){
                while(sum - nums[head] >= s){
                    sum -= nums[head];
                    head++;
                }
                if(tail - head < min)
                    min = tail - head;
            }
        }
        
        if(min == INT_MAX)
            return 0;
        else
            return min;
    }
};

