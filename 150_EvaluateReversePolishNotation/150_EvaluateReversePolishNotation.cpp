/*************************************************************************
	> File Name: 150_EvaluateReversePolishNotation.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct  6 18:57:13 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty())
            return 0;
            
        stack<int> num;
        for(auto i:tokens){
            if(i == "+"){
                int b = num.top();
                num.pop();
                int a = num.top();
                num.pop();
                num.push(a + b);
            } else if(i == "-"){
                int b = num.top();
                num.pop();
                int a = num.top();
                num.pop();
                num.push(a - b);
            } else if(i == "*"){
                int b = num.top();
                num.pop();
                int a = num.top();
                num.pop();
                num.push(a * b);
            } else if(i == "/"){
                int b = num.top();
                num.pop();
                int a = num.top();
                num.pop();
                num.push(a / b);
            } else {
                num.push(stoi(i));
            }
        }
        return num.top();
    }
};
