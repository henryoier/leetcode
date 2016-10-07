/*************************************************************************
	> File Name: 163_MissingRanges.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct  6 22:04:37 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if(nums.empty())
            result.push_back(getRange(lower, upper));
        
        for(int i = 0; i < nums.size(); i++){
            if(i == 0) 
                if(nums[i] > lower)
                    result.push_back(getRange(lower, nums[i] - 1));
                else{}
            else { 
                if(nums[i] > nums[i - 1] + 1)  // mind overload!
                    result.push_back(getRange(nums[i - 1] + 1, nums[i] - 1));
            }
            if(i == nums.size() - 1 && nums[i] < upper)
                result.push_back(getRange(nums[i] + 1, upper));
        }
            
        return result;
    }
private:
    string getRange(int a, int b){
        if(a == b)
            return to_string(a);
        else
            return to_string(a) + "->" + to_string(b);
    }
};
