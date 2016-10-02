/*************************************************************************
	> File Name: 394_DecodeString.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  1 20:13:04 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string result;
        int pos = 0;
        int num = 0;
        while(pos < s.length()){
            if(s[pos] >= '0' && s[pos] <= '9'){
                num = num * 10 + s[pos] - '0';
                pos++;
            } else if(s[pos] >= 'a' && s[pos] <= 'z'){
                result += s[pos]; 
                pos++;
            } else if(s[pos] == '['){
                int index = findRightBracket(s.substr(pos)) + pos;
                string str = decodeString(s.substr(pos + 1, index - pos - 1));
                for(int k = 0; k < num; k++){
                    result += str;
                }
                num = 0;
                pos = index + 1;
            }
        }
        return result;
    }
private:
    int findRightBracket(string str){
        int count = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '[')
                count++;
            if(str[i] == ']'){
                count--;
                if(count == 0)
                    return i;
            }
        }
        return str.length();
    }
};
