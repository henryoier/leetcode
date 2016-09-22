/*************************************************************************
	> File Name: 139_WordBreak.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 22 17:03:24 2016
 ************************************************************************/

#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length(), m = wordDict.size();
        if(n == 0)
            return true;
            
        bool f[n + 1];
        fill(f, f + n + 1, false);
        
        f[0] = true;
        for(int i = 1; i <= n; i++){
            for(auto j:wordDict){
                if(i >= j.length()){
                    if(s.substr(i - j.length(), j.length()) == j)
                        if(f[i - j.length()]){
                            f[i] = true;
                            break;
                        }
                }
            }
        }
        return f[n];
    }
};

int main() {
    Solution newSolution;
    unordered_set<string> wordDict({"leet","code","a","b"});

    cout << newSolution.wordBreak("leetcode", wordDict) << endl;

    return 0;
}
