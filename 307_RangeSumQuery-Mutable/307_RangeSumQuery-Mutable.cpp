/*************************************************************************
	> File Name: 307_RangeSumQuery-Mutable.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  2 11:29:58 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        bit = vector<int>(nums.size() + 1, 0);
        
        for(int i = 0; i < n; i++)
            add(i + 1, nums[i]);
            
        this->nums = nums;
    }

    void update(int i, int val) {
        add(i + 1, val - nums[i]);
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        return query(j) - query(i - 1);
    }

private:
    int n;
    vector<int> bit;
    vector<int> nums;
    
    int query(int i){
        int result = 0;
        i++;
        result += bit[i];
        while(i > 0){
            i = i - lower_bit(i);
            result += bit[i];
        }
        return result;
    }
    
    void add(int i, int val){
        bit[i] += val;
        while(i + lower_bit(i) <= n){
            i = i + lower_bit(i);
            bit[i] += val;
        }
    }
    
    int lower_bit(int a){
        return a & (-a);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
