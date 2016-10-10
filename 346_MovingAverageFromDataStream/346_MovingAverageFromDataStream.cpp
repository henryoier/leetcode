/*************************************************************************
	> File Name: 346_MovingAverageFromDataStream.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  9 21:55:02 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        if(q.size() < size){
            q.push(val);
            sum += val;
            return (double)sum / q.size();
        } else {
            sum -= q.front();
            q.pop();
            q.push(val);
            sum += val;
            return (double)sum / q.size();
        }
    }
private:
    queue<int> q;
    int sum = 0;
    int size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
