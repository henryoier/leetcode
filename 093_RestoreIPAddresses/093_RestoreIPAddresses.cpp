/*************************************************************************
	> File Name: 093_RestoreIPAddresses.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 19 14:03:42 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
    public:
    vector<string> restoreIpAddresses(string s) {
                vector<string> result;
                string num[4];
                dfs(0, num, s, result);
                
                return result;
            
    }
    private:
    void dfs(int pos, string *num, string s, vector<string>& result){
                if(pos == 4)
        if(s.length() == 0){
                            result.push_back(num[0] + "." + num[1] + "." + num[2] + "." + num[3]); 
                            return;
                        
        } else
                        return;
                        
                if(s.length() == 0)
                    return;
                
                string now = s.substr(0, 1);
                num[pos] = now;
                dfs(pos + 1, num, s.substr(1), result);
                
        if(s.length() > 1 && s[0] != '0'){
                        string now = s.substr(0, 2);
                        num[pos] = now;
                        dfs(pos + 1, num, s.substr(2), result);
                    
        }
                
        if(s.length() > 2 && s[0] != '0'){
                        string now = s.substr(0,3);
            if(now <= "255"){
                                num[pos] = now;
                                dfs(pos + 1, num, s.substr(3), result);
                            
            }
                    
        }

            
    }

};

int main() {
    return 0;
}
