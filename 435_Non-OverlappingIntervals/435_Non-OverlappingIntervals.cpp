/*************************************************************************
	> File Name: 435_Non-OverlappingIntervals.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct 31 21:26:30 2016
 ************************************************************************/

#include<iostream>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), [=](const Interval a, const Interval b){
            if(a.start < b.start || (a.start == b.start && a.end < b.end))
                return true;
            else
                return false;
        });
        
        int count = 0;
        int cur_end = INT_MIN;
        for(auto i:intervals){
            if(i.start >= cur_end){
                cur_end = i.end;
                count++;
            } else if(i.end <= cur_end)
                cur_end = i.end;
        }
        return intervals.size() - count;
    }
};
