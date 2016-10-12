/*************************************************************************
	> File Name: 339_NestedListWeightSum.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct 12 12:39:25 2016
 ************************************************************************/

#include<iostream>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return getSum(nestedList, 1);    
    }
private:
    int getSum(vector<NestedInteger>& nestedList, int depth){
        int result = 0;
        for(auto i:nestedList){
            if(i.isInteger())
                result += i.getInteger() * depth;
            else
                result += getSum(i.getList(), depth + 1);
        }
        return result;
    }
};
