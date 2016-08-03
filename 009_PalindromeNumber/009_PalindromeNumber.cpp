/*************************************************************************
	> File Name: 009_PalindromeNumber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Aug  3 16:14:22 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int num[20];
        int len = 0;
        if(x < 0)
            return false;
        
        while(x>0){
            num[len] = x % 10;
            x = x / 10;
            len++;
        }
        
        int head = 0, tail = len - 1;
        while(head <= tail){
            if(num[head++] != num[tail--])
                return false;
        }
        return true;
    }
};

int main(){
    int x;
    cin >> x;

    Solution newSolution;
    cout << newSolution.isPalindrome(x);

    return 0;
}
