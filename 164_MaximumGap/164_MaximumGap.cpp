/*************************************************************************
	> File Name: 164_MaximumGap.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct 13 22:56:04 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
            
        int maxN = *max_element(nums.begin(), nums.end()), minN = *min_element(nums.begin(), nums.end());
        
        if(maxN == minN)
            return 0;
            
        int len = nums.size() - 1;
        int gap = ceil((double)(maxN - minN) / len);
        
        vector<int> bucket_min(len + 1, INT_MAX);
        vector<int> bucket_max(len + 1, INT_MIN);
        
        int maxGap = 0;
        for(int i = 0; i < nums.size(); i++){
            int idx = (nums[i] - minN) / gap;
            if(nums[i] > bucket_max[idx])
                bucket_max[idx] = nums[i];
            if(nums[i] < bucket_min[idx])
                bucket_min[idx] = nums[i];
        }
        
        for(int i = 0; i <= len; i++){
            if(bucket_min[i] != INT_MAX){
                if(bucket_min[i] - minN > maxGap)
                    maxGap = bucket_min[i] - minN;
                minN = bucket_max[i];
            }
        }
        
        return maxGap;
    }
};
