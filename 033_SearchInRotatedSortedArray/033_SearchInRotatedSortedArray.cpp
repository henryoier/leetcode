/*************************************************************************
	> File Name: 033_SearchInRotatedSortedArray.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Aug 28 13:49:48 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
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
            } else {
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
            }
        }
        if(nums[head] == target)
            return head;
        else
            return -1;
    }
};
