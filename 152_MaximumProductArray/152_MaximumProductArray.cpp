/*************************************************************************
	> File Name: 152_MaximumProductArray.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 22 23:43:21 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
            
        int curr = 1, max = INT_MIN, last = 1;
        for(int i = 0; i < nums.size(); i++){
            curr *= nums[i];
       
            if(curr < 0){
                if(last == 1){
                    if(curr > max)
                        max = curr;
                    else{}
                    
                    last = curr;
                    curr = 1;
                } else {
                    curr *= last;
                    last = 1;
                    
                    if(curr > max)
                        max = curr;
                    else{}
                }
            } else if(curr == 0){
                if(curr > max)
                        max = curr;
                else{}
                        
                last = 1;
                curr = 1;
            } else{
                if(curr > max)
                    max = curr;
                else{}
            }
        }
        
        curr = 1;
        last = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            curr *= nums[i];
       
            if(curr < 0){
                if(last == 1){
                    if(curr > max)
                        max = curr;
                    else{}
                    
                    last = curr;
                    curr = 1;
                } else {
                    curr *= last;
                    last = 1;
                    
                    if(curr > max)
                        max = curr;
                    else{}
                }
            } else if(curr == 0){
                if(curr > max)
                        max = curr;
                else{}
                        
                last = 1;
                curr = 1;
            } else{
                if(curr > max)
                    max = curr;
                else{}
            }
        }
        return max;
    }
};
