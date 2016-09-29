/*************************************************************************
	> File Name: 232_ImplementQueueUsingStacks.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 00:12:11 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(s.size() != 1){
            cache.push(s.top());
            s.pop();
        }
        s.pop();
        while(cache.size() != 0){
            s.push(cache.top());
            cache.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        int res;
        while(s.size() != 1){
            cache.push(s.top());
            s.pop();
        }
        res = s.top();
        while(cache.size() != 0){
            s.push(cache.top());
            cache.pop();
        }
        return res;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.size() == 0;
    }
private:
    stack<int> s;
    stack<int> cache;
};
