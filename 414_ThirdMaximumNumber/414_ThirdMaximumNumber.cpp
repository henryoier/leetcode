/*************************************************************************
	> File Name: 414_ThirdMaximumNumber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct 23 11:00:44 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> heap;
        unordered_set<int> hash;
        
        for(auto i:nums){
            if(hash.count(i))
                continue;
            else{
                hash.insert(i);
                if(heap.size() < 3)
                    heap.push(i);
                else
                    if(i > heap.top()){
                        heap.pop();
                        heap.push(i);
                    }
            }
        }
        if(heap.size() == 3)
            return heap.top();
        else{
            heap.pop();
            return heap.top();
        }
    }
};
