/*************************************************************************
	> File Name: 268_MissingNumber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 00:15:38 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.push_back(-1);
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] != i && nums[i] != -1){
                int e = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = e;
            }
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == -1)
                return i;
        return 0;
    }
};
