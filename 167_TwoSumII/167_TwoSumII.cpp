/*************************************************************************
	> File Name: 167_TwoSumII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 26 01:03:30 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; numbers[i] <= target / 2; i++){
            int index = binarySearch(numbers, target - numbers[i], i + 1, numbers.size() - 1);
            if(index != -1)
                return vector<int>({i + 1, index + 1});    
        }
        return vector<int>();
    }
private:
    int binarySearch(vector<int> numbers, int target, int head, int tail){
        while(head < tail){
            int mid = (head + tail + 1)/2;
            if(numbers[mid] > target)
                tail = mid - 1;
            else
                head = mid;
        }
        if(numbers[head] == target)
            return head;
        else
            return -1;
    }
};
