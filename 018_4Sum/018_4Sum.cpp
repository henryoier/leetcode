/*************************************************************************
	> File Name: 018_4Sum.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct  5 11:50:13 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4)
            return result;
            
        sort(nums.begin(), nums.end());
        for(auto i = nums.begin(); i != prev(nums.end(), 3); i++){
            if(i != nums.begin() && *i == *prev(i))
                continue;
            for(auto j = next(i); j != prev(nums.end(), 2); j++){
                if(j != next(i) && *j == *prev(j))
                    continue;
                    
                auto k = next(j);
                auto l = prev(nums.end());
                
                
                while(k < l){
                    if(k != next(j) && *k == *prev(k)){
                        k++;
                        continue;
                    }
                    if(l != prev(nums.end()) && *l == *next(l)){
                        l--;
                        continue;
                    }
                    int sum = *i + *j + *k + *l;
                    if(sum == target){
                        result.push_back(vector<int>({*i, *j, *k, *l}));
                        k++;
                    } else 
                        if(sum < target) k++;
                        else l--;
                }
            }
        }
        return result;
    }
};
