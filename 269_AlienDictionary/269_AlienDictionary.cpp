/*************************************************************************
	> File Name: 269_AlienDictionary.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct 11 23:08:49 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> post;
        unordered_map<char, unordered_set<char>> pre;
        unordered_set<char> letters;
        
        for(auto i:words)
            letters.insert(i.begin(), i.end());
            
        for(int i = 0; i < words.size() - 1; i++)
            for(int j = i + 1; j < words.size(); j++){
                int k;
                for(k = 0; k < min(words[i].length(), words[j].length()); k++){
                    if(words[i][k] != words[j][k]){
                        post[words[i][k]].insert(words[j][k]);
                        pre[words[j][k]].insert(words[i][k]);
                        break;
                    }
                }
                if(k == words[j].length() && words[i].length() > words[j].length())
                    return "";
            }
        
        string result;
        queue<char> q;
        
        for(auto i:letters)
            if(pre[i].size() == 0)
                q.push(i);
            
        while(!q.empty()){
            char cur = q.front();
            q.pop();
            result += cur;
            
            for(auto i:post[cur]){
                pre[i].erase(cur);
                if(pre[i].size() == 0)
                    q.push(i);
            }
        }
        
        return result.length() == letters.size()?result:"";
    }
};
