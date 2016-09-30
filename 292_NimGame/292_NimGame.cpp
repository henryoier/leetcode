/*************************************************************************
	> File Name: 292_NimGame.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 16:40:56 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return !(n % 4 == 0);
    }
};
