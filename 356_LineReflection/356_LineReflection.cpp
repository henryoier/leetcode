/*************************************************************************
	> File Name: 356_LineReflection.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct 10 13:11:19 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if(points.size() < 2)
            return true;
            
        sort(points.begin(), points.end(), comp);
        auto is_unique = unique(points.begin(), points.end());
        points.erase(is_unique, points.end());
        
        unordered_map<int, unordered_set<int>> y;
        for(auto i:points){
            y[i.first].insert(i.second);
        }
        
        double mid;
        int n = points.size();
        if(n % 2 == 0){
            mid = (double)(points[n / 2 - 1].first + points[n / 2].first) / 2;
            for(int i = n / 2 - 1; i >= 0; i--){
                if((mid- points[i].first != points[n - i - 1].first - mid) || !y[points[i].first].count(points[n - i - 1].second))
                    return false;
            }
            return true;
        } else {
            mid = (double)points[n / 2].first;
            for(int i = n / 2 - 1; i >= 0; i--){
                if((mid- points[i].first != points[n - i - 1].first - mid) || !y[points[i].first].count(points[n - i - 1].second))     
                    return false;
            }
            return true;
        }
    }
private:
    struct compare{
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.first < b.first;
        }
    } comp;
};
