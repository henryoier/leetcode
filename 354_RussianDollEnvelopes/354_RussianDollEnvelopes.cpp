/*************************************************************************
	> File Name: 354_RussianDollEnvelopes.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct 27 23:17:31 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [=](pair<int, int> a, pair<int, int>b){
           return a.first < b.first || (a.first == b.first && a.second > b.second); 
        });
        
        vector<int> result;
        for(auto i : envelopes) {
            auto it = lower_bound(result.begin(), result.end(), i.second);
            if(it == result.end()) result.push_back(i.second);
            else *it = i.second;
        }
        
        return result.size();
    }
};
