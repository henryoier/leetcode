/*************************************************************************
	> File Name: 162_FindPeakElement.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 23 13:51:00 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(auto i = nums.begin(); i != nums.end();i++){
            if(i == nums.begin() && *i > *(i + 1))
                return 0;
            if(i == nums.end() - 1 && *i > *(i - 1))
                return nums.size() - 1;
            if(*i > *(i - 1) && *i > *(i + 1))
                return distance(nums.begin(), i);
        }    
        return 0;
    }
};


