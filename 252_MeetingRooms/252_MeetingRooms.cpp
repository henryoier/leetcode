/*************************************************************************
	> File Name: 252_MeetingRooms.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 21:52:06 2016
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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty())
            return true;
        
        sort(intervals.begin(), intervals.end(), compare);
        for(int i = 0; i < intervals.size() - 1; i++){
            if(intervals[i + 1].start < intervals[i].end)
                return false;
        }
        return true;
    }

    struct comp{
        bool operator()(Interval a, Interval b){
            return a.start < b.start;
        }
    } compare;
};
