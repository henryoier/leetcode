/*************************************************************************
	> File Name: 169_MajorityElement.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 26 16:29:53 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        
        for(auto i:nums){
            if(hash.find(i) != hash.end()){
                hash[i]++;
                if(hash[i] > (n / 2))
                    return i;
            } else {
                hash.insert({i, 1});
                if(hash[i] > (n / 2))
                    return i;
            }
        }
        return 0;
    }
};

