/*************************************************************************
	> File Name: 398_RandomPickIndex.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  1 13:34:08 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(index.find(nums[i]) == index.end()){
                index.insert({nums[i], vector<int>(1, i)});
            } else {
                index[nums[i]].push_back(i);
            }
        }
    }
    
    int pick(int target) {
        return *next(index[target].begin(), rand() % index[target].size());
    }
private:
    unordered_map<int, vector<int>> index;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

 class Solution {
private:
    vector<int> nums;
    
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        srand(time(0));
    }
    
    int pick(int target) {
        int ans;
        
        for (int i = 0, cnt = 1; i < nums.size(); i++) {
            if (nums[i] == target && ((rand() % cnt++) == 0)) { ans = i; }
        }
        
        return ans;
    }
};
