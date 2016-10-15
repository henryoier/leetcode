/*************************************************************************
	> File Name: 187_RepeatedDNASequences.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct 15 00:58:59 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string, int> hash;
        
        for(int start = 0; start + 9 < s.length(); start++){
            string cur = s.substr(start, 10);
            if(hash[cur] == 1)
                result.push_back(cur);
            hash[cur]++;
                
        }
        
        return result;
    }
};
