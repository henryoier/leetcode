/*************************************************************************
	> File Name: 440_KthSmallestInLexicographicalOrder.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct 28 17:21:52 2016
 ************************************************************************/

#include<iostream>

class Solution {
public:
    int findKthNumber(int n, int k) {
        long cur = 1;
        k--;
        while(k > 0){
            int count = 0;
            for(long first = cur, last = cur; first <= n; first *= 10, last = (last + 1) * 10 - 1){
                count += min((long)n, last) - first + 1;
            }
            if(k >= count){
                k -= count;
                cur++;
            } else {
                k -= 1;
                cur *= 10;
            }
        }
        return cur;
    }
};
