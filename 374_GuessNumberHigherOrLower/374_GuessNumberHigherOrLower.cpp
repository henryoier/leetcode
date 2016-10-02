/*************************************************************************
	> File Name: 374_GuessNumberHigherOrLower.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  2 16:33:50 2016
 ************************************************************************/

#include<iostream>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int head = 1, tail = n;
        
        while(head < tail){
            int mid = head + (tail - head)/2;
            int cond = guess(mid);
            if(cond == 0)
                return mid;
            else if(cond == 1) 
                head = mid + 1;
            else
                tail = mid;
        }
        
        return head;
    }
};
