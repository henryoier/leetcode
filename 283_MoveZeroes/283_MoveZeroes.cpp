/*************************************************************************
	> File Name: 283_MoveZeroes.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 11:58:56 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0;
    	for (int i=0;i<nums.size();i++){
    		if (nums[i]!=0) nums[index++]=nums[i];
    	}
    	while(index<nums.size()){
    		nums[index++]=0;
    	} 
    }
};
