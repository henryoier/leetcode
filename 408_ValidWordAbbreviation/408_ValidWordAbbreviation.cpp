/*************************************************************************
	> File Name: 408_ValidWordAbbreviation.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  9 23:03:07 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int h1 = 0, h2 = 0;
        
        string num = "";
        while(h2 < abbr.length()){
            if(abbr[h2] >= '0' && abbr[h2] <= '9'){
                if(num == "" && abbr[h2] == '0')
                    return false;
                num += abbr[h2];
                h2++;
            } else {
                if(num != ""){
                    h1 += stoi(num);
                    num = "";
                }
                if(word[h1] != abbr[h2])
                    return false;
                h1++;
                h2++;
            }
        }
        if(num != "")
            h1 += stoi(num);
        
        if(h1 == word.length())
            return true;
        else
            return false;
    }
};
