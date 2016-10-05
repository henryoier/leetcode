/*************************************************************************
	> File Name: 350_IntersectionOfTwoArrayII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct  4 23:52:21 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> s;
        vector<int> result;
        
        for(auto i:nums1){
            if(s.find(i) == s.end())
                s.insert({i, 1});
            else
                s[i] += 1;
        }
        
        for(auto i:nums2){
            if(s.find(i) != s.end()){
                result.push_back(i);
                if(s[i] == 1)
                    s.erase(i);
                else
                    s[i] -= 1;
            }
        }
        
        return result;
    }
};
