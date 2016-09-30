/*************************************************************************
	> File Name: 278_FirstBadVersion.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 11:10:31 2016
 ************************************************************************/

#include<iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int head = 1, tail = n;
        while(head < tail){
            int mid = head + (tail - head)/2;
            
            if(isBadVersion(mid)){
                tail = mid;
            }else{
                head = mid + 1;
            }
        }
        return head;
    }
};
