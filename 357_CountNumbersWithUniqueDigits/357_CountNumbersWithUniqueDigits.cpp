/*************************************************************************
	> File Name: 357_CountNumbersWithUniqueDigits.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Nov  3 17:09:15 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;
        for(int i = 1; i <= min(n, 10); i++){
            int cur = 9;
            for(int k = 2; k <= i; k++)
                cur *= (9 - k + 2);
            sum += cur;
        }
        return sum;
    }
};
