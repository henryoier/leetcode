/*************************************************************************
	> File Name: 267_PalindromePermutationII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct 21 15:24:11 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        map<char, int> freq;
        for(auto c:s)
            freq[c]++;
        
        vector<string> result;
        vector<char> cur(s.length());
        
        int countOdd = 0;
        for(auto i:freq)
            if(i.second % 2 != 0)
                countOdd++;
                
        if(countOdd > 1)
            return result;
            
        dfs(0, s.length() - 1, freq, result, cur);
        
        return result;
    }
private:
    void dfs(int start, int end, map<char, int>& freq, vector<string>& result, vector<char>& cur){
        if(start > end){
            string temp;
            for(auto i:cur)
                temp = temp + i;
            result.push_back(temp);
        }
        if(start == end){
            for(auto i:freq)
                if(i.second == 1)
                    cur[start] = i.first;
            dfs(start + 1, end - 1, freq, result, cur);
        }
        for(auto i = freq.begin(); i != freq.end(); ++i){
            if(i->second >= 2){
                cur[start] = i->first;
                cur[end] = i->first;
                i->second -= 2;
                dfs(start + 1, end - 1, freq, result, cur);
                i->second += 2;
            }
        }
    }
};
