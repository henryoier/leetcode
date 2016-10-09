/*************************************************************************
	> File Name: 266_PalindromePermutation.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  8 20:49:30 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> hash;
        for(auto i:s)
            hash[i]++;
        int odd = 0, even = 0;
        for(auto i:hash){
            if(i.second % 2 == 0)
                even++;
            else
                odd++;
        }
        if(odd <= 1)
            return true;
        else
            return false;
    }
};
