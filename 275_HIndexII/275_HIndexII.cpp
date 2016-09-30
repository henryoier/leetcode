/*************************************************************************
	> File Name: 275_HIndexII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 10:29:37 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0)
            return 0;
            
        int head = 0, tail = citations.size() - 1;
        
        while(head < tail){
            int mid = head + (tail - head) / 2;
            if(citations[mid] < (citations.size() - mid))
                head = mid + 1;
            else
                tail = mid;
        }
        if(citations[head] < (citations.size() - head))
            return 0;
        else
            return citations.size() - head;
    }
};

