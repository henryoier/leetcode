/*************************************************************************
	> File Name: 370_RangeAddition.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct 17 23:35:38 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> nums(length + 1, 0);
        for(i:updates){
            nums[i[0]] += i[2];
            nums[i[1] + 1] -= i[2];
        }
        
        for(int i = 1; i < length; i++)
            nums[i] += nums[i - 1];
            
        nums.resize(length);
        
        return nums;
    }
};
