/*************************************************************************
	> File Name: 384_ShuffleAnArray.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct 23 14:56:09 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        origin = nums;
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;    
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuf = origin;
        for(int size = origin.size(); size > 0; size --){
            int idx = rand() % size;
            swap(shuf[idx], shuf[size - 1]);
        }
        return shuf;
    }
private:
    vector<int> origin;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
