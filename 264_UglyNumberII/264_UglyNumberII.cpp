/*************************************************************************
	> File Name: 264_UglyNumberII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 23:41:53 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n];
        ugly[0] = 1;
        int min2 = 2, min3 = 3, min5 = 5;
        int count2 = 1, count3 = 1, count5 = 1;
        
        for(int i = 1; i < n; i++ ){
            ugly[i] = min(min2, min(min3, min5));
            if(ugly[i] == min2) min2 = 2 * ugly[count2++];
            if(ugly[i] == min3) min3 = 3 * ugly[count3++];
            if(ugly[i] == min5) min5 = 5 * ugly[count5++];
        }
        return ugly[n - 1];
    }
};
