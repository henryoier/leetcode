/*************************************************************************
	> File Name: 291_WordPatternII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct 20 21:54:01 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, int> count;
        unordered_map<char, string> decode;
        unordered_set<string> used;
        
        if(pattern.length() > str.length())
            return false;
        
        for(auto i:pattern)
            count[i]++;
            
        dfs(pattern, str, decode, count, used, str.length(), 0);
        
        return found;
    }
private:
    bool found = false;
    
    void dfs(string pattern, string str, unordered_map<char, string> decode, unordered_map<char, int> count, unordered_set<string> used, int str_len, int already_len){
        if(pattern.empty()) 
            if(str.empty()){
                found = true;
                return;
            } else
                return;
        cout << pattern << ' ' << str << endl;
        char cur = pattern[0];
        if(decode.count(cur)){
            if(str.find(decode[cur]) == 0)
                dfs(pattern.substr(1), str.substr(decode[cur].length()), decode, count, used, str_len, already_len);
            else
                return;
        } else {
            for(int len = 1; already_len + len * count[cur] <= str_len && found != true; len++){
                if(!used.count(str.substr(0, len))){
                    decode[cur] = str.substr(0, len);
                    used.insert(str.substr(0, len));
                    dfs(pattern.substr(1), str.substr(len), decode, count, used, str_len, already_len + len * count[cur]);
                    used.erase(str.substr(0, len));
                }
            }
        }    
    }
};
