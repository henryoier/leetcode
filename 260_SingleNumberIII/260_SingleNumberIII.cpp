/*************************************************************************
	> File Name: 260_SingleNumberIII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 23:05:49 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= - diff;
        
        vector<int> res({0, 0});
        for(auto i:nums){
            if((i & diff) == 0){
                res[0] ^= i;
            }else {
                res[1] ^= i;
            }
        }
        return res;
    }
};
