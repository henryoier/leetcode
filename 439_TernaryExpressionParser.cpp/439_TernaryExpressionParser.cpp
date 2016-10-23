/*************************************************************************
	> File Name: 439_TernaryExpressionParser.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct 23 16:22:18 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string parseTernary(string expression) {
        if(expression.find('?') == string::npos)
            return expression;
        else{
            int idx1 = expression.find('?');
            string exp1 = expression.substr(0, idx1);
            int idx2 = findComma(expression.substr(idx1));
            
            if(parseTernary(exp1) == "T")
                return parseTernary(expression.substr(idx1 + 1, idx2 - 1));
            else
                return parseTernary(expression.substr(idx1 + idx2 + 1));
            }
    }
private:
    int findComma(string exp){
        int count = 0;
        for(int i = 0; i < exp.length(); i++){
            if(exp[i] == '?')
                count++;
            if(exp[i] == ':')
                if(count == 1)
                    return i;
                else
                    count--;
        }
        return 0;
    }
};
