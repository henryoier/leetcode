/*************************************************************************
	> File Name: 140_WordBreakII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 22 20:18:07 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length(), m = wordDict.size();
        
        if(n == 0)
            return vector<string>();
        
        vector<vector<int>> f;
        f.push_back(vector<int>(1, 0));
        
        for(int i = 1; i <= n; i++){
            vector<int> temp;
            for(auto j:wordDict){
                if(i >= j.length()){
                    if(s.substr(i - j.length(), j.length()) == j)
                        if(f[i - j.length()].size() != 0){
                            temp.push_back(i - j.length());
                        }
                }
            }
            f.push_back(temp);
        }
        return getResult(s, f, n);
    }
private:
    vector<string> getResult(string s, vector<vector<int>> f, int cur){
        vector<string> result;
        
        if(cur == 0)
            return vector<string>();
        else
            for(auto i:f[cur]){
                vector<string> temp = getResult(s, f, i);
                if(temp.size() == 0)
                    temp.push_back(s.substr(i, cur - i));
                else
                    for(int j = 0; j != temp.size(); j++){
                        temp[j] = temp[j] + ' ' + s.substr(i, cur - i);
                    }
                result.insert(result.end(), temp.begin(), temp.end());
            }
        return result;
    }
};

int main() {
    return 0;
}
