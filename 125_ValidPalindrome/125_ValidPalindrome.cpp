/*************************************************************************
	> File Name: 125_ValidPalindrome.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 21 12:07:08 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0)
            return true;
        else {
            int i = 0;
            int j = s.length() - 1;
            while(i <= j){
                while(true){
                    if(('9' >= s[i] && s[i] >= '0') || ('z' >= s[i] && s[i] >= 'a') || ('Z' >= s[i] && s[i] >= 'A') || i == s.length())
                        break;
                    else
                        i++;
                }
                
                while(true){
                    if(('9' >= s[j] && s[j] >= '0') || ('z' >= s[j] && s[j] >= 'a') || ('Z' >= s[j] && s[j] >= 'A') || j < 0)
                        break;
                    else
                        j--;
                }
                
                if(tolower(s[i]) != tolower(s[j]))
                    return false;
                else
                    if(j - i < 2)
                        return true;
                    else {
                        i++;
                        j--;
                    }
            }
            return true;
        }
    }
};

int main() {
    return 0;
}
