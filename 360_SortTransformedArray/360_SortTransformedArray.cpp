/*************************************************************************
	> File Name: 360_SortTransformedArray.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct 10 13:29:55 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> result;
        if(a == 0){
            if(b > 0){
                for(auto i:nums)
                    result.push_back(b*i + c);
                return result;
            } else if(b < 0){
                reverse(nums.begin(), nums.end());
                for(auto i:nums)
                    result.push_back(b*i + c);
                return result;
            } else {
                result.resize(nums.size(), c);
                return result;
            }
        } else {
            double mid = 0 - (double)b / (2 * a);
            bool nega =  a < 0;
            int left, right;
            
            if(mid < nums[0]){
                left = -1;
                right = 0;
            } else if(mid > nums[nums.size() - 1]){
                right = nums.size();
                left = nums.size() - 1;
            } else {
                for(int i = 0; i < nums.size() - 1; i++){
                    if(mid >= nums[i] && mid <= nums[i + 1]){
                        left = i;
                        right = i + 1;
                        break;
                    }
                }
            }
            
            while(left >= 0 && right < nums.size()){
                if(mid - nums[left] < nums[right] - mid){
                    result.push_back(a*nums[left]*nums[left] + b*nums[left] + c);
                    left--;
                } else {
                    result.push_back(a*nums[right]*nums[right] + b*nums[right] + c);
                    right++;
                }
            }
            while(left >= 0){
                result.push_back(a*nums[left]*nums[left] + b*nums[left] + c);
                left--;
            }
            while(right < nums.size()){
                result.push_back(a*nums[right]*nums[right] + b*nums[right] + c);
                right++;
            }
            if(nega)
                reverse(result.begin(), result.end());
                
            return result;
        }
    }
};
