/*************************************************************************
	> File Name: 373_FindKPairsWithSmallestSums.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct  4 21:40:07 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> next(nums1.size(), 0);
        vector<int> idx(nums1.size(), 0);
        vector<pair<int, int>> result;
        if(nums1.size() == 0 || nums2.size() == 0)
            return result;
            
        for(int i = 0; i < nums1.size(); i++)
            next[i] = nums1[i] + nums2[0];
        
        for(int i = 0; i < k && i < nums1.size() * nums2.size(); i++){
            int minN = INT_MAX, min_index;
            for(int j = 0; j < nums1.size(); j++)
                if(next[j] < minN){
                    minN = next[j];
                    min_index = j;
                }
            result.push_back(pair<int, int>(nums1[min_index], nums2[idx[min_index]]));
            if(idx[min_index] < nums2.size() - 1)
                next[min_index] = nums1[min_index] + nums2[++idx[min_index]];
            else
                next[min_index] = INT_MAX;
        }
        return result;        
    }
};
