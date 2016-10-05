/*************************************************************************
	> File Name: 349_IntersectionOfTwoArrays.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct  4 23:47:54 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> result;
        
        for(auto i:nums1)
            s.insert(i);
        
        sort(nums2.begin(), nums2.end());
        
        for(int i = 0; i < nums2.size(); i++){
            if(i == 0 || nums2[i] != nums2[i - 1])
                if(s.find(nums2[i]) != s.end())
                    result.push_back(nums2[i]);
        }
        
        return result;
    }
};
