/*************************************************************************
	> File Name: 303_RangeSumQuery-Immutable.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 22:43:45 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        sum.push_back(0);
        for(auto i:nums){
            sum.push_back(i + *prev(sum.end()));
        }    
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];    
    }
private:
    vector<int> sum; 
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
