/*************************************************************************
	> File Name: 436_FindRightInterval.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Nov  3 16:37:37 2016
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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        unordered_map<int, int> idx;
        vector<int> result(intervals.size());
        
        for(int i = 0; i < intervals.size(); i++)
            idx[intervals[i].start] = i;
            
        sort(intervals.begin(), intervals.end(), [=](const Interval& a, const Interval& b){
           return a.start < b.start;
        });
        
        for(int i = 0; i < intervals.size(); i++){
            auto it = upper_bound(intervals.begin(), intervals.end(), intervals[i].end, comp);
            if(it == intervals.end())
                result[idx[intervals[i].start]] = -1;
            else
                result[idx[intervals[i].start]] = idx[it->start];
        }
        return result;
    }
private:
    struct compare{
        int compValue(const Interval& a){
            return a.start;
        }
        int compValue(const int a){
            return a;
        }
        
        template<typename T1, typename T2>
        bool operator()(T1 const t1, T2 const t2){
            return compValue(t1) <= compValue(t2);
        }
    }comp;
};
