/*************************************************************************
	> File Name: 220_ContainsDuplicateIII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct  3 16:30:40 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> s;
        if(k == 0 || t < 0)
            return false;
            
        for(int i = 0; i < nums.size(); i++){
            if(s.empty())
                s.insert(nums[i]);
            else if(s.size() <= k){
                s.insert(nums[i]);
                auto idx = s.find(nums[i]);
                if((idx != s.begin() && *prev(idx) + t >= nums[i]) || (idx != prev(s.end()) && *next(idx) - t <= nums[i]))
                    return true;
            } else {
                auto ide = s.find(nums[i - k - 1]);
                s.erase(ide);
                s.insert(nums[i]);
                auto idx = s.find(nums[i]);
                if((idx != s.begin() && *prev(idx) + t >= nums[i]) || (idx != prev(s.end()) && *next(idx) - t <= nums[i]))
                    return true;
            }
        }
        return false;
    }
};
