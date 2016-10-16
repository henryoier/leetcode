/*************************************************************************
	> File Name: 259_3SumSmaller.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct 15 22:07:02 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int result = 0;
        for(int i = 0; i < nums.size() - 2; i++){
            int j = i + 1, k = nums.size() - 1;
            while(j < k){ 
                if(nums[i] + nums[j] + nums[k] >= target)
                    k--;
                else{
                    result += k - j;
                    j++;
                }
            }
        }
        
        return result;
    }
};
