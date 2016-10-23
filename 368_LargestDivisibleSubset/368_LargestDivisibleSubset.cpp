/*************************************************************************
	> File Name: 368_LargestDivisibleSubset.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct 23 11:51:29 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> result;
        if(nums.empty())
            return result;
            
        sort(nums.begin(), nums.end());
        vector<int> f(nums.size(), 1);
        vector<int> last(nums.size(),-1);
        
        for(int i = 0; i < nums.size() - 1; i++)
            for(int j = i + 1; j < nums.size(); j++)
                if(nums[j] % nums[i] == 0)
                    if(f[i] + 1 > f[j]){
                        f[j] = f[i] + 1;
                        last[j] = i;
                    }
                        
        int idx = distance(f.begin(), max_element(f.begin(), f.end()));
        while(idx != -1){
            result.insert(result.begin(), nums[idx]);
            idx = last[idx];
        }
        
        return result;
    }
};
