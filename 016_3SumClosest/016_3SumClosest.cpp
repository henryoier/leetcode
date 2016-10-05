/*************************************************************************
	> File Name: 016_3SumClosest.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct  5 11:00:42 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_gap = INT_MAX;
        int min_sum;
        
        sort(nums.begin(), nums.end());
        
        for(auto i = nums.begin(); i != prev(nums.end(), 2); i++){
            auto j = next(i);
            auto k = prev(nums.end());
            
            while(j < k){
                int sum = *i + *j + *k;
                int gap = abs(target - sum);
                if(gap < min_gap){
                    min_gap = gap;
                    min_sum = sum;
                }
                
                if(sum < target) j++;
                else k--;
            }
        }
        
        return min_sum;
    }
};
