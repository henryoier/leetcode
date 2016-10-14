/*************************************************************************
	> File Name: 213_HouseRobberII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct 13 23:11:28 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) 
            return 0;
        if(n < 4)
            return *max_element(nums.begin(), nums.end());
            
        int result = 0;
        for(int i = 0; i < n; i++){
            vector<int> f(n - 1, 0);
            int end = (i + n - 2) % n;
        
            for(int j = end, count = n - 2; count >= 0; j = (j + n - 1) % n, count--){
                if(count == n-2 || count == n - 3)
                    f[count] = nums[j];
                else
                    f[count] = max(f[count + 1], nums[j] + f[count + 2]);
            }
            if(f[0] > result)
                result = f[0];
        }
        
        return result;
    }
};
