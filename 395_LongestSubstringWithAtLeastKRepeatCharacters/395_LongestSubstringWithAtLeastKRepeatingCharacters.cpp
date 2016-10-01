/*************************************************************************
	> File Name: 395_LongestSubstringWithAtLeastKRepeatingCharacters.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  1 14:55:51 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int countN[26] = {};
        for(auto i:s){
            if(countN[i - 'a'] == 0){
                countN[i - 'a'] = count(s.begin(), s.end(), i);
            }
        }
        for(auto i:s){
            if(countN[i - 'a'] < k){
                string snew = s;
                int max = 0, temp, index;
                while((index = snew.find(i)) != string::npos){
                    if((temp = longestSubstring(snew.substr(0, index), k)) > max)
                        max = temp;
                    snew = snew.substr(index + 1);
                }
                if((temp = longestSubstring(snew, k)) > max)
                        max = temp;
                return max;
            } 
        }
        return s.length();
    }
};
