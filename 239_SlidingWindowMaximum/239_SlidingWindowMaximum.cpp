/*************************************************************************
	> File Name: 239_SlidingWindowMaximum.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 21:07:37 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0 || k == 0)
            return vector<int>();
            
        map<int, int, greater<int>> q;
        vector<int> result;
        
        for(int i = 0; i <= nums.size() - k; i++){
            if(i == 0){
                for(int j = i; j < i + k; j++)
                    if(q.find(nums[j]) == q.end())
                        q.insert({nums[j], 1});
                    else
                        q[nums[j]]++;
                result.push_back(q.begin()->first);
            } else {
                if(q[nums[i - 1]] == 1)
                    q.erase(nums[i - 1]);
                else
                    q[nums[i - 1]]--;
                    
                if(q.find(nums[i + k - 1]) != q.end())
                    q[nums[i + k - 1]]++;
                else
                    q.insert({nums[i + k - 1], 1});
                result.push_back(q.begin()->first);
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++){
            if(!dq.empty() && dq.front() == i-k)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1)
                result.push_back(nums[dq.front()]);
        }
        return result;
    }
};
