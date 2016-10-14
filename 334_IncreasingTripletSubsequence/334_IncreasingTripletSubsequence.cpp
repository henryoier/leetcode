/*************************************************************************
	> File Name: 334_IncreasingTripletSubsequence.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct 14 16:15:24 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int cand1 = INT_MAX, cand2 = INT_MAX;
        
        for(int i = 0; i < nums.size();i++){
            if(nums[i] > cand2)
                return true;
            else {
                if(nums[i] <= cand2 && nums[i] > cand1)
                    cand2 = nums[i];
                else
                    if(nums[i] <= cand1)
                        cand1 = nums[i];
            }
        }
        return false;
    }
};
