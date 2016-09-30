/*************************************************************************
	> File Name: 290_WordPattern.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 16:29:30 2016
 ************************************************************************/

#include<iostream>

using namespace std;

bool wordPattern(string pattern, string str) {
    unordered_map<char,string> hash_1;
    unordered_map<string,char> hash_2;
    stringstream ss(str);
    string s;
    
    for (auto c : pattern) {
        if (!(ss >> s)) {
            return false;
        }
       
        if (hash_1.find(c) == hash_1.end() && hash_2.find(s) == hash_2.end()) {
            hash_1[c] = s;
            hash_2[s] = c;
        }
        
        if (hash_1[c] != s || hash_2[s] != c) {
            return false;
        }
    }
    
    if (!ss.eof()) {
        return false;
    }
    
    return true;
}
