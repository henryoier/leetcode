/*************************************************************************
	> File Name: 091_DecodeWays.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 19 13:31:11 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
    public:
    int numDecodings(string s) {
                if (s.length() == 0)
                    return 0;
                    
                int f[s.length()];
                fill(f, f + s.length(), 0);
                
                int previous;
                
        for(int i = 0; i < s.length(); i++){
            if(i == 0){
                                if(s[0] != '0')
                                    f[i] = 1;
                                else
                                    f[i] = 0;
                            
            } else if (i == 1){
                                if(s[i] != '0')
                                    f[i] = f[i - 1];
                                if(previous * 10 + s[i] - '0' <= 26 && previous != 0)
                                    f[i] += 1;
                            
            } else {
                                if(s[i] != '0')
                                    f[i] = f[i - 1];
                                if(previous * 10 + s[i] - '0' <= 26 && previous != 0)
                                    f[i] += f[i - 2];
                            
            }
                        
                        previous = s[i] - '0';
                    
        }
                
                return f[s.length() - 1];
            
    }

};

int main() {
    return 0;
}
