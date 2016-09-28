/*************************************************************************
	> File Name: 217_ContainsDuplicate.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 27 22:03:37 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        
        for(auto i:nums){
            if(hash.find(i) != hash.end())
                return true;
            else
                hash.insert(i);
        }
        
        return false;
    }
};
