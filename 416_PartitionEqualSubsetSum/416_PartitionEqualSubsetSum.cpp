/*************************************************************************
	> File Name: 416_PartitionEqualSubsetSum.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  9 14:09:59 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> sum;
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        if(total % 2 != 0)
            return false;
        else{
            sum.insert(0);
            for(auto i:nums){
                vector<int> cur;
                for(auto j:sum){
                    if(i + j == total / 2)
                        return true;
                    cur.push_back(i + j);
                }
                for(auto j:cur)
                    sum.insert(j);
            }
            return false;
        }
    }
};
