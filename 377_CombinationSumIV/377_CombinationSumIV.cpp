/*************************************************************************
	> File Name: 377_CombinationSumIV.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  2 15:58:10 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> f(target + 1, 0);
        
        f[0] = 1;
        for(int i = 0; i <= target; i++){
            if(f[i] != 0)
                for(int j = 0; j < nums.size(); j++)
                    if(i + nums[j] <= target)
                        f[i + nums[j]] += f[i];
        }
                        
        return f[target];
    }
};
