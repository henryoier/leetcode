/*************************************************************************
	> File Name: 154_FindMinimumInRotatedSortedArrayII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 23 13:02:03 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMinHalf(nums, 0, nums.size());
    }
private:
    int findMinHalf(vector<int> nums, int begin, int end){
        if(end - begin == 1)
            return nums[begin];
        if(end - begin == 2)
            return min(nums[begin], nums[begin + 1]);
        
        int mid = begin + (end - begin)/2;
        
        if(nums[begin] <= nums[end - 1])
            return min(findMinHalf(nums, begin, mid + 1), findMinHalf(nums, mid + 1, end));
        else
            if(nums[begin] <= nums[mid])
                return findMinHalf(nums, mid + 1, end);
            else
                return findMinHalf(nums, begin, mid + 1);
    }
};
