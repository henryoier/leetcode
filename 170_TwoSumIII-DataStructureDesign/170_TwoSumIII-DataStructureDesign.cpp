/*************************************************************************
	> File Name: 170_TwoSumIII-DataStructureDesign.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct  6 23:48:21 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    nums[number]++;   
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(auto i:nums){
	        if((nums.count(value - i.first) && value != i.first * 2) || (i.first * 2 == value && i.second >= 2))
	            return true;
	    }
	    return false;
	}

private:
    //vector<int> nums;
    unordered_map<int, int> nums;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
