/*************************************************************************
	> File Name: 362_DesignHitCounter.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct 12 14:53:58 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);
        while(q.front() + 299 < timestamp)
            q.pop();
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(q.front() + 299 < timestamp && !q.empty())
            q.pop();
        return q.size();
    }
private:
    queue<int> q;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
