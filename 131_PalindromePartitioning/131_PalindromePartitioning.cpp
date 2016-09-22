/*************************************************************************
	> File Name: 131_PalindromePartitioning.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 22 14:09:31 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > result;
        if(s.length() == 0)
            return result;
            
        for(int i = 1; i < s.length();i++){
            if(isPalindrome(s.substr(0, i))){
                vector<vector<string>> right = partition(s.substr(i));
                    
                for(int j = 0; j < right.size(); j++) {
                    right[j].insert(right[j].begin(), s.substr(0, i));
                }
                result.insert(result.end(), right.begin(), right.end());
            }
        }
        
        if(isPalindrome(s))
            result.push_back(vector<string>(1, s));
            
        return result;
    }
private:
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
