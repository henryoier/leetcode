/*************************************************************************
	> File Name: 391_PerfectRectangle.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct 17 19:08:09 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int minX = INT_MAX, minY = INT_MAX, maxX = 0, maxY = 0;
        unordered_set<string> hash;
        
        int area = 0;
        for(auto i: rectangles){
            minX = min(minX, i[0]);
            minY = min(minY, i[1]);
            maxX = max(maxX, i[2]);
            maxY = max(maxY, i[3]);
            
            area += (i[2] - i[0]) * (i[3] - i[1]);
            
            if(hash.count(to_string(i[0]) + ' ' + to_string(i[1])))
                hash.erase(to_string(i[0]) + ' ' + to_string(i[1]));
            else
                hash.insert(to_string(i[0]) + ' ' + to_string(i[1]));
                
            if(hash.count(to_string(i[2]) + ' ' + to_string(i[1])))
                hash.erase(to_string(i[2]) + ' ' + to_string(i[1]));
            else
                hash.insert(to_string(i[2]) + ' ' + to_string(i[1]));
                
            if(hash.count(to_string(i[0]) + ' ' + to_string(i[3])))
                hash.erase(to_string(i[0]) + ' ' + to_string(i[3]));
            else
                hash.insert(to_string(i[0]) + ' ' + to_string(i[3]));
                
            if(hash.count(to_string(i[2]) + ' ' + to_string(i[3])))
                hash.erase(to_string(i[2]) + ' ' + to_string(i[3]));
            else
                hash.insert(to_string(i[2]) + ' ' + to_string(i[3]));    
        }
        
        if(area != (maxY- minY) * (maxX - minX))
            return false;
        if(hash.size() != 4 || !hash.count(to_string(minX) + ' ' + to_string(minY)) || !hash.count(to_string(maxX) + ' ' + to_string(minY)) || !hash.count(to_string(minX) + ' ' + to_string(maxY)) || !hash.count(to_string(maxX) + ' ' + to_string(maxY)))
            return false;
            
        return true;
    }
};
