/*************************************************************************
	> File Name: 280_WiggleSort.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  8 23:27:18 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() == 0)
            return;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 1; i += 2){
            nums.insert(nums.begin() + i + 1, *prev(nums.end()));
            nums.erase(prev(nums.end()));
        }
    }
};
