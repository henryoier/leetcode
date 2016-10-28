/*************************************************************************
	> File Name: 330_PatchingArray.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct 28 16:39:03 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int numAdd = 0;
        long range = 1;
        for(int i = 0; i < nums.size();){
            if(nums[i] > range) {
                range *= 2;
                numAdd++;
            } else {
                range = range + nums[i];
                i++;
            }
            if(range > n)
                return numAdd; 
        }
        while(range <= n){
            numAdd++;
            range *= 2;
        }
        return numAdd;
    }
};
