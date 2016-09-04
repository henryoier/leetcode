/*************************************************************************
	> File Name: 069_SqrtX.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Sep  4 19:35:07 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x < 0)
            return INT_MIN;

        long i = 0, x1 = x;
        for(i = 0; i*i <= x1; i++);
        
        return i - 1;
    }
};

int main() {
    Solution newSolution;

    cout << newSolution.mySqrt(2147395600) << endl;

    return 0;
}
