/*************************************************************************
	> File Name: 215_KthLargestElementInAnArray.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 27 14:46:53 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for(auto i:nums){
            if(min_heap.size() < k){
                min_heap.push(i);
            } else {
                if(i > min_heap.top()){
                    min_heap.pop();
                    min_heap.push(i);
                }
            }
        }
        
        return min_heap.top();
    }
};
