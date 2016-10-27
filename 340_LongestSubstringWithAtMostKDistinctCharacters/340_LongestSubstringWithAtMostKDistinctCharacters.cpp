/*************************************************************************
	> File Name: 340_LongestSubstringWithAtMostKDistinctCharacters.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct 27 00:11:18 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int start, end;
        unordered_map<char, int> seen;
        
        if(s.empty() || k == 0)
            return 0;
           
        start = 0; end = 0;
        seen[s[start]]++;
        
        int maxLen = 1;
        while(end < s.length() - 1){
            end++;
            seen[s[end]]++;
            while(seen.size() > k){
                seen[s[start]]--;
                if(seen[s[start]] == 0)
                    seen.erase(s[start]);
                start++;
            }
            maxLen = max(maxLen, end - start + 1);
        }
        
        return maxLen;
    }
};
