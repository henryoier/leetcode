/*************************************************************************
	> File Name: 287_FindTheDuplicateNumber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  2 14:09:54 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        
        slow = nums[slow];
        fast = nums[nums[fast]];
            
        while(nums[slow] != nums[fast]){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int index = 0;
        while(nums[index] != nums[slow]){
            index = nums[index];
            slow = nums[slow];
        }
        
        return nums[index];
    }
};
