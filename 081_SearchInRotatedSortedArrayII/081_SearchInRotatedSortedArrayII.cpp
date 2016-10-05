/*************************************************************************
	> File Name: 081_SearchInRotatedSortedArrayII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct  5 14:46:21 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int head = 0, tail = nums.size() - 1;
        
        while(head < tail){
            int mid = head + (tail - head) / 2;
            if(nums[head] < nums[tail]){
                if(nums[mid] >= target)
                    tail = mid;
                else
                    head = mid + 1;
            } else if(nums[head] > nums[tail]){
                if(nums[mid] >= nums[head]){
                    if(nums[head] > target || nums[mid] < target)
                        head = mid + 1;
                    else
                        tail = mid;
                } else {
                    if(nums[mid] < target && nums[tail] >= target)
                        head = mid + 1;
                    else
                        tail = mid;
                }
            } else {
                if(nums[tail] == target)
                    return true;
                tail--;
                while(tail > head && nums[tail] == nums[tail + 1]){
                        tail--;
                }
            }
        }
        if(nums[head] == target)
            return true;
        else
            return false;    
    }
};
