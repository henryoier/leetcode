/*************************************************************************
	> File Name: 301_RemoveInvalidParentheses.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct 29 23:36:31 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> hash;
        queue<string> q;
        vector<string> result;
        q.push(s);
        hash.insert(s);
        
        while(!q.empty()){
            vector<string> curGen;
            while(!q.empty()){
                curGen.push_back(q.front());
                q.pop();
            }
            for(int i = 0; i < curGen.size(); i++){
                if(isValid(curGen[i]))
                    result.push_back(curGen[i]);
            }
            if(result.size() != 0)
                break;
            else
                if(curGen[0].length() > 0)
                    for(int i = 0; i < curGen.size(); i++)
                        for(int j = 0; j < curGen[i].length(); j++){
                            if(curGen[i][j] == '(' || curGen[i][j] == ')'){
                                string newStr = curGen[i];
                                newStr.erase(j, 1);
                                if(!hash.count(newStr)){
                                    q.push(newStr);
                                    hash.insert(newStr);
                                }
                            }
                        }
        }
        return result;
    }
private:
    bool isValid(string s){
        int count = 0;
        for(auto i:s){
            if(i == '(')
                count++;
            if(i == ')')
                count--;
            if(count < 0)
                return false;
        }
        return count == 0;
    }
};
