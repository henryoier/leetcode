/*************************************************************************
	> File Name: 228_SummaryRanges.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 28 20:21:15 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 1)
            return vector<string>(1, to_string(nums[0]));
            
        int head;
        vector<string> result;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                head = nums[i];
            } else if(i == nums.size() - 1){
                if(nums[i] - nums[i - 1] != 1){
                    if(nums[i - 1] != head)
                        result.push_back(to_string(head) + "->" + to_string(nums[i - 1]));
                    else
                        result.push_back(to_string(head));
                    result.push_back(to_string(nums[i]));
                } else
                    result.push_back(to_string(head) + "->" + to_string(nums[i]));
            } else if(nums[i] - nums[i - 1] != 1){
                if(nums[i - 1] != head)
                    result.push_back(to_string(head) + "->" + to_string(nums[i - 1]));
                else
                    result.push_back(to_string(head));
                head = nums[i];
            } else {}
        }  
        return result;
    }
};
