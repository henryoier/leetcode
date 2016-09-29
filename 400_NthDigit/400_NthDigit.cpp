/*************************************************************************
	> File Name: 400_NthDigit.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 28 20:00:52 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int len = 1;
        int number;
        
        while(n > 9 * len * pow(10, len - 1) ) { n = n - 9 * len * pow(10, len - 1);len++; }
        
        int index = n / len;
        int num = n % len;
        
        cout << index << num << endl;
        if(num == 0){
            number = pow(10, len - 1) - 1 + index;
            return number % 10;
        } else{
            number = pow(10, len - 1) + index;
            for(; num < len; num++) number = number / 10;
            return number % 10;
        }
        
    }
private:
    long pow(int x, int y){
        int result = 1;
        while(y > 0){
            result *= x;
            y--;
        }
        return result;
    }
};
