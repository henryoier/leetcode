/*************************************************************************
	> File Name: 242_ValidAnagram.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 22:19:41 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};

bool isAnagram(string s, string t) {
        if (s.length() != t.length()) { return false; }
        int freqs[26] = {}; 
        for (char c : s) { freqs[c - 'a']++; }
        for (char c : t) { if (--freqs[c - 'a'] < 0) { return false; }}
        return true;
}
