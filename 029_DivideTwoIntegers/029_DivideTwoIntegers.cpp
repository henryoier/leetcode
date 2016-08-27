/*************************************************************************
	> File Name: 029_DivideTwoIntegers.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Aug 11 19:03:40 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        long dividend1 = dividend, divisor1 = divisor, result = 0;
        if(divisor == 0)
            return INT_MAX;
        if(divisor1 == -1){
            result = 0 - dividend;
            return result<=INT_MAX?result:INT_MAX;
        }

        if(divisor == 1){
            result = dividend;
            return result;
        }

        bool positive = (dividend1 > 0 && divisor1 > 0) || (dividend1 < 0 && divisor1 < 0);
        
        if(dividend1 < 0)
            dividend1 = 0 - dividend1;
    
        if(divisor1 < 0)
            divisor1 = 0 - divisor1; 
        
        while(dividend1 >= divisor1){
            dividend1 -= divisor1;
            result++;
        }    
        if(positive)
            return result<=INT_MAX?result:INT_MAX;
        else
            return 0 - result;
    }
};

int main(){
    Solution newSolution;

    //cout << INT_MAX;
    cout << newSolution.divide(-2147483648, -1) << endl;
    return 0;
}
