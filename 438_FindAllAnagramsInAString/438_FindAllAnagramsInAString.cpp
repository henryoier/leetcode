/*************************************************************************
	> File Name: 438_FindAllAnagramsInAString.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct 24 10:18:49 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        
        unordered_map<char, int> expected;
        for(auto i:p)
            expected[i]++;
        
        unordered_map<char, int> seen;
        for(int i = 0; i + p.length() <= s.length(); i++){
            if(i == 0)
                for(int j = 0; j < p.length(); j++)
                    seen[s[j]]++;
            else{
                seen[s[i + p.length() - 1]]++;
                if(seen[s[i - 1]] == 1)
                    seen.erase(s[i - 1]);
                else
                    seen[s[i - 1]]--;
            }
            bool legal = true;
            for(auto i:expected){
                if(!seen.count(i.first) || seen[i.first] != i.second){
                    legal = false;
                    break;
                }
            }    
            if(legal)
                result.push_back(i);
        }    
        
        return result;
    }
};
