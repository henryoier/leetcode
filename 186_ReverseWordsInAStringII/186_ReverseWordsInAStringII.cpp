/*************************************************************************
	> File Name: 186_ReverseWordsInAStringII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 00:58:56 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        for(int start = 0, idx = (s.find(' ') == -1)?s.length():s.find(' '); start < s.length(); start = idx + 1, idx = (s.find(' ', start) == -1?s.length():s.find(' ', start)))
            reverse(s.begin() + start, s.begin() + idx);
    }
};
