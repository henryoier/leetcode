/*************************************************************************
	> File Name: 155_MinStack.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 22 23:59:20 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        vector<int> s();
    }
    
    void push(int x) {
        s.push_back(x);
        if(x < min)
            min = x;
    }
    
    void pop() {
        if(s[s.size() - 1] == min){
            s.erase(s.end() - 1);
            auto index = min_element(s.begin(), s.end());
            if(index == s.end())
                min = INT_MAX;
            else
                min = *index;
        }else {
            s.erase(s.end() - 1);
        }
    }
    
    int top() {
        return s[s.size() - 1]; 
    }
    
    int getMin() {
        return min;
    }
private:
    vector<int> s;
    int min = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
