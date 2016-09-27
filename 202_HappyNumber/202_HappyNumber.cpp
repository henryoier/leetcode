/*************************************************************************
	> File Name: 202_HappyNumber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 27 00:07:07 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash;
        hash.insert(n);
        
        while(true){
            int now = 0;
            while(n > 0){
                now += (n % 10) * (n % 10);
                n = n / 10;
            }
            if(now == 1)
                return true;
            if(hash.find(now) != hash.end())
                return false;
            hash.insert(now);
            n = now;
            now = 0;
        }
    }
};
