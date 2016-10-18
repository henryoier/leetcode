/*************************************************************************
	> File Name: 365_WaterAndJugProblem.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct 17 23:19:22 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z &&z % gcd(x, y) == 0);
    }
private:
    int gcd(int a, int b){
        if(a % b == 0)
            return b;
        else
            return gcd(b, a % b);
    }
};
