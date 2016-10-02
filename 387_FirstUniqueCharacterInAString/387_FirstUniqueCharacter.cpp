/*************************************************************************
	> File Name: 387_FirstUniqueCharacter.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  1 22:35:44 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_set<char> found;
        for(int i = 0; i < s.length();i++){
            if(found.find(s[i]) != found.end())
                continue;
            if(s.find(s[i], i + 1) == string::npos)
                return i;
            else
                found.insert(s[i]);
        }
                
        return -1;
    }
};
