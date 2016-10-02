/*************************************************************************
	> File Name: 376_WiggleSubsequence.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  2 16:25:02 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int result = 0;
        bool inc;
        bool first = true;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0)
                result++;
            else if(first)
                if(nums[i] > nums[i - 1]){
                    result++;
                    inc = true;
                    first = false;
                } else if(nums[i] < nums[i - 1]){
                    result++;
                    inc = false;
                    first = false;
                } else {}
            else 
                if(nums[i] > nums[i - 1] && !inc){
                    result++;
                    inc = true;
                } else if(nums[i] < nums[i - 1] && inc){
                    result++;
                    inc = false;
                }
        }
        return result;
    }
};
