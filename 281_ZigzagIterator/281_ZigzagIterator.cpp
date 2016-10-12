/*************************************************************************
	> File Name: 281_ZigzagIterator.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct 12 15:16:25 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        q.push(v1);
        q.push(v2);
    }

    int next() {
        int result = *(q.front().begin());
        q.front().erase(q.front().begin());
        if(q.size() != 1){
            q.push(q.front());
            q.pop();
        }
        
        return result;
    }

    bool hasNext() {
        while(!q.empty())
            if(q.front().empty())
                q.pop();
            else
                break;
        return !q.empty();  
    }
private:
    queue<vector<int>> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
