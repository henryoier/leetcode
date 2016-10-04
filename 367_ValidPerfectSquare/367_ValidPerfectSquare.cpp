/*************************************************************************
	> File Name: 367_ValidPerfectSquare.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct  4 11:25:04 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int head = 1, tail = num;
        while(head < tail){
            cout << head << ' ' << tail << endl;
            int mid = head + (tail - head) / 2;
            if(num / mid <= mid)
                tail = mid;
            else
                head = mid + 1;
        }
        if(head * head == num)
            return true;
        else
            return false;
    }
};
