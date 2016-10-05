/*************************************************************************
	> File Name: 409_LongestPalindrome.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct  4 21:19:53 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash;
        
        for(auto i:s){
            if(hash.find(i) == hash.end())
                hash.insert({i, 1});
            else    
                hash[i] += 1;
        }
        
        bool hasOdd = false;
        int count = 0;
        
        for(auto i:hash){
            if(i.second % 2 == 0){
                count += i.second;
            } else {
                hasOdd = true;
                count += i.second - 1;
            }
        }
        if(!hasOdd)
            return count;
        else
            return count + 1;
    }
};
