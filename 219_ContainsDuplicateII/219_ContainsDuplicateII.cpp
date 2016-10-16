/*************************************************************************
	> File Name: 219_ContainsDuplicateII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 27 22:28:00 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.size() <= k){
                if(s.find(nums[i]) != s.end())
                    return true;
                else
                    s.insert(nums[i]);
            } else {
                s.erase(nums[i - k - 1]);
                if(s.find(nums[i]) != s.end())
                    return true;
                else
                    s.insert(nums[i]);
            }
        }
        return false;
    }
};
