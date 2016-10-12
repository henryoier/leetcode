/*************************************************************************
	> File Name: 364_NestedListWeightSumII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct 12 13:15:42 2016
 ************************************************************************/

#include<iostream>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<pair<int, int>> result;
        getSum(nestedList, 1, result);
        
        int maxDepth = 0;
        for(auto i:result)
            maxDepth = max(maxDepth, i.second);
        
        int sum = 0;
        for(auto i:result)
            sum += i.first * (maxDepth - i.second + 1);
        
        return sum;
    }
private:
    void getSum(vector<NestedInteger>& nestedList, int depth, vector<pair<int, int>>& result){
        int cur = 0;
        for(auto i:nestedList){
            if(i.isInteger())
                cur += i.getInteger();
            else 
                getSum(i.getList(), depth + 1, result);
                
        }
        
        result.push_back(pair<int, int>(cur, depth));
    }
};
