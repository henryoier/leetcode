/*************************************************************************
	> File Name: 020_ValidParentheses.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Aug  5 23:53:49 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        char stack[s.length()];
        int top = 0;

        for(int i = 0; i < s.length(); i++){
            if(top > 0 && match(get_top_element(stack, top), s[i]))
                pop(stack, top);
            else
                push(stack, top, s[i]);
        }

        if(top == 0)
            return true;
        else
            return false;
    }

private:
    bool match(char a, char b){
        if((a == '(' && b == ')' )||(a =='[' && b == ']') || (a == '{' && b == '}'))
            return true;
        else
            return false;
    }

    char get_top_element(char *stack, int top){
        return stack[top - 1];
    }

    void pop(char *stack, int& top){
        top--;
    }

    void push(char *stack, int& top, char ch){
        stack[top++] = ch;
    }
};

int main(){
    Solution newSolution;
    cout << newSolution.isValid("({})") << endl;

    return 0;
}
