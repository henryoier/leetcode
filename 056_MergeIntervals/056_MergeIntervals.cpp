/*************************************************************************
	> File Name: 056_MergeIntervals.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep  6 14:45:51 2016
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
    vector<Interval> merge(vector<Interval>& intervals) {
        //sort(intervals.begin(), intervals.end());
        if(intervals.size() == 0)
            return intervals;
            
        for(int i = 0; i < intervals.size() - 1; i++)
                for(int j = i + 1; j < intervals.size(); j++)
                    if(!(intervals[i].start > intervals[j].end) && !(intervals[i].end < intervals[j].start)){
                        Interval a = intervals[i], b = intervals[j];
                        Interval newInterval(min(a.start, b.start), max(a.end, b.end));

                        intervals.erase(intervals.begin() + j);
                        intervals.erase(intervals.begin() + i);
                        intervals.insert(intervals.begin() + i, newInterval);
                        j = i;
                    }
        return intervals;     
    }
};

int main() {
    return 0;
}
