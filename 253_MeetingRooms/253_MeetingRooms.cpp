/*************************************************************************
	> File Name: 253_MeetingRooms.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 22:02:17 2016
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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty())
            return 0;
            
        vector<int> room;
        sort(intervals.begin(), intervals.end(), comp);
        
        for(auto i:intervals){
            if(room.empty())
                room.push_back(i.end);
            else{
                int index = -1;
                int minGap = INT_MAX;
                for(int j = 0; j < room.size(); j++)
                    if(i.start >= room[j])
                        if(i.start - room[j] < minGap){
                            minGap = i.start - room[j];
                            index = j;
                        }
                if(index == -1){
                    room.push_back(i.end);
                } else {
                    room[index] = i.end;
                }
            }
        }
        return room.size();
    }
private:
    struct compare{
        bool operator()(Interval a, Interval b){
            return a.start < b.start;
        }
    } comp;
};
