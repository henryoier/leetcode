/*************************************************************************
	> File Name: 347_TopKFrequentElements.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct  5 21:31:27 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    struct comp{
        bool operator()(pair<int, int> a, pair<int, int>b){
            return a.second >= b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> min_heap;
        
        unordered_map<int, int> count;
        
        for(auto i:nums){
            count[i]++;
        }
        for(auto j:count){
            cout << j.first << j.second << endl;
            if(min_heap.size() < k){
                min_heap.push(pair<int, int>(j.first, j.second));
            } else {
                if(j.second < min_heap.top().second){}
                else{
                    min_heap.pop();
                    min_heap.push(pair<int, int>(j.first, j.second));
                }
            }
        }
        vector<int> result;
        while(!min_heap.empty()){
            result.push_back(min_heap.top().first);
            min_heap.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
