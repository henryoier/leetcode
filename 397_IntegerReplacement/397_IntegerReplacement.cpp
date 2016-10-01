/*************************************************************************
	> File Name: 397_IntegerReplacement.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  1 13:56:17 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        return getRep(n); 
    }
    
    int getRep(long n){
        if(n == 1)
            return 0;
        else
            if(n % 2 == 0)
                return getRep(n / 2) + 1;
            else
                return min(getRep(n + 1), getRep(n - 1)) + 1;
    }
};
