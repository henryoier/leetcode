/*************************************************************************
	> File Name: 415_AddStrings.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  9 14:02:31 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = min(num1.length(), num2.length()), carry = 0;
        string result;
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for(int i = 0; i < n; i++){
            int now = num1[i] - '0' + num2[i] - '0' + carry;
            carry = now / 10;
            result.insert(result.length(), 1, (char)now % 10 + '0');
        }
        if(num1.length() > n){
            for(int i = n; i < num1.length(); i++){
                int now = num1[i] - '0' + carry;
                carry = now / 10;
                result.insert(result.length(), 1, (char)now % 10 + '0');
            }
        } 
        if(num2.length() > n){
            for(int i = n; i < num2.length(); i++){
                int now = num2[i] - '0' + carry;
                carry = now / 10;
                result.insert(result.length(), 1, (char)now % 10 + '0');
            }
        }
        if(carry != 0)
            result.insert(result.length(), 1, '1');
        reverse(result.begin(), result.end());
        
        return result;
    }
};
