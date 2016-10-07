/*************************************************************************
	> File Name: 159_LongestSubstringWithAtMostTwoDistinctCharacters.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct  6 21:07:57 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int head = 0, tail = 0;
        unordered_map<char, int> hash;
        int cur = 0;
        int max = 0;
        
        while(tail < s.length()){
            if(hash.size() < 2){
                hash[s[tail]]++;
                tail++;
                if(tail - head > max)
                    max = tail - head;
            } else {
                if(hash.count(s[tail])){
                    hash[s[tail]]++;
                    tail++;
                    if(tail - head > max)
                        max = tail - head;
                } else {
                    while(hash[s[head]] != 1){
                        hash[s[head]]--;
                        head++;
                    }
                    hash.erase(s[head]);
                    head++;
                    hash.insert({s[tail], 1});
                    tail++;
                    if(tail - head > max)
                        max = tail - head;
                }
            }
        }
        return max;
    }
};
