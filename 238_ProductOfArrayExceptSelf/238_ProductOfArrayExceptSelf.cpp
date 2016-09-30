/*************************************************************************
	> File Name: 238_ProductOfArrayExceptSelf.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 20:14:19 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int countZero = 0;
        for(auto i:nums){
            if(i == 0){
                countZero++;
                if(countZero > 1)
                    break;
            } else {
                product = product * i;
            }
        }
        
        if(countZero > 1)
            return vector<int>(nums.size(), 0);
            
        vector<int> result;
        for(auto i:nums){
            if(countZero == 0){
                result.push_back(product / i);
            } else {
                if(i == 0)
                    result.push_back(product);
                else
                    result.push_back(0);
            }
        }
        return result;
    }
};
