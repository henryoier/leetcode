/*************************************************************************
	> File Name: 390_EliminationGame.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  1 22:04:38 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        return dp(1,1,true,n); 
    }

private:
    int dp(int start, int interval, bool left, int num){
        if(num == 1)
            return start;
        
        if(num % 2 == 0)
            if(left)
                return dp(start + interval, interval * 2, false, num / 2);
            else
                return dp(start, interval * 2, true, num / 2);
        else
            if(left)
                return dp(start + interval, interval * 2, false, (num - 1) / 2);
            else
                return dp(start + interval, interval * 2, true, (num - 1) / 2);
        
    }
};
