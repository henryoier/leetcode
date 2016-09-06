/*************************************************************************
	> File Name: 057_InsertInterval.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep  6 16:36:00 2016
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        for(auto i = intervals.begin(); i != intervals.end(); i++){
            if(newInterval.end < i->start){
                intervals.insert(i, newInterval);
                return intervals;
            } else if(newInterval.start > i->end){
                continue;
            } else {
                newInterval.start = min(newInterval.start, i->start);
                newInterval.end = max(newInterval.end, i->end);
                intervals.erase(i);
                return insert(intervals, newInterval);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals; 
    }
};

int main() {
    return 0;
}
