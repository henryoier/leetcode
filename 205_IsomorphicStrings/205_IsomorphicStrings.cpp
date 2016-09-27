/*************************************************************************
	> File Name: 205_IsomorphicStrings.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 27 01:02:21 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> map1, map2;
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(map1.find(s[i]) == map1.end() && map2.find(t[i]) == map2.end()){
                count++;
                map1.insert({s[i], count});
                map2.insert({t[i], count});
            } else if(map1[s[i]] == map2[t[i]]) {} 
                else return false;
        }
        return true;
    }
};
