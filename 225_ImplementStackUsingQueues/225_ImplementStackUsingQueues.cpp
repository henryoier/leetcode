/*************************************************************************
	> File Name: 225_ImplementStackUsingQueues.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 28 13:28:14 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        s.push_back(x);    
    }

    // Removes the element on top of the stack.
    void pop() {
        s.erase(prev(s.end(), 1));
    }

    // Get the top element.
    int top() {
        return *prev(s.end());
    }

    // Return whether the stack is empty.
    bool empty() {
        return s.size() == 0;
    }
private:
    vector<int> s;
};
