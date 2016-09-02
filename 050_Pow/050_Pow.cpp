/*************************************************************************
	> File Name: 050_Pow.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep  1 21:54:28 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0)
            return 1.0 / power(x, -n);
        else
            return power(x, n);
    }

private:
    double power(double x, long n){
        if(n == 0)
            return 1.0;
        double half = power(x, n / 2);

        if(n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};

int main() {
    Solution newSolution;
    cout << newSolution.myPow(2.00000, -2147483648) << endl;

    return 0;
}

