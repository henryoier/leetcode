/*************************************************************************
	> File Name: 371_SumOfTwoIntegers.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct  3 23:41:00 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0, res = 0;
        for(int i = 0; i < 32; i++){
            int a1 = a & (1 << i);
            int b1 = b & (1 << i);
            res |= a1 xor b1 xor carry;
            carry = ((a1 & b1)|(a1 & carry)|(b1 & carry)) << 1;
        }
        return res;
    }
};
