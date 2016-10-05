/*************************************************************************
	> File Name: 030_SubstringWithConcatenationOfAllWords.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct  5 15:00:04 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> expected;
        vector<int> result;
        
        int len = words[0].length();
        int n = words.size();
        
        for(auto word:words)
            expected[word]++;
        
        for(int i = 0; i + n * len <= s.length(); i++){
            unordered_map<string, int> seen;
            int j = i;
            int count = 0;
            while(true){
                string now = s.substr(j, len);
                if(expected.find(now) == expected.end() || seen[now] == expected[now])
                    break;
                else{
                    count++;
                    seen[now]++;
                    j += len;
                }
            }
            if(count == n)
                result.push_back(i);
        }
        return result;
    }
};
