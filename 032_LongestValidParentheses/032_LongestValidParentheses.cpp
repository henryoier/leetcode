/*************************************************************************
	> File Name: 032_LongestValidParentheses.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Aug 27 22:40:55 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0;
        int lastPos = -1, unpair = 0;
        for(int pos = 0; pos < s.length(); pos++ ){
            if(s[pos] == '(')
               unpair++;
            else
                if(unpair == 0)
                    lastPos = pos;
               else{
                   unpair--;
                   if(unpair == 0)
                        if(pos - lastPos > max)
                            max = pos - lastPos;
               }
        }
        
        lastPos = s.length();
        unpair = 0;
        for(int pos = s.length(); pos >= 0; pos--){
            if(s[pos] == ')')
                unpair++;
            else
                if(unpair == 0)
                    lastPos = pos;
                else{
                    unpair--;
                    if(unpair == 0)
                        if(lastPos - pos > max)
                            max = lastPos - pos;
                }
        }
        return max;
    }
};

int main(){
    Solution newSolution;
    cout << newSolution.longestValidParentheses("(()()") << endl;
    return 0;
}
