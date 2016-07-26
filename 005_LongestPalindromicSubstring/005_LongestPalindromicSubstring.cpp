/*************************************************************************
	> File Name: 005_LongestPalindromicSubstring.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Jul 26 17:00:21 2016
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1, maxIndex;
        
        if(s.length() == 1)
            return s;

        for(int i = 1; i < s.length() - 1; i++){
            int len = 1;
            while(s[i - len] == s[i + len] && i - len >= 0 && i + len <= s.length())
                len++;
            len--;
            if(len * 2 + 1 > maxLen){
                maxLen = len * 2 +1;
                maxIndex = i - len;
            }
        }
        
         
        for(int i = 0; i + 1 < s.length(); i++){
            if(s[i] == s[i+1]){
                int len = 1;
                while(s[i - len] == s[i + len + 1] && i - len >= 0 && i + len + 1 <= s.length())
                    len++;
                len--;
                if((len + 1) * 2 > maxLen){
                    maxLen = (len + 1)* 2;
                    maxIndex = i - len;
                }
            }else{
                continue;
            }
        }

        return s.substr(maxIndex, maxLen);
    }
};

int main(){
    string s;
    Solution newSolution;

    cin >> s;
    cout << newSolution.longestPalindrome(s) << endl;

    return 0;
}
