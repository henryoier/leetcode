/*************************************************************************
	> File Name: 149_MaxPointsOnALine.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct  6 18:16:31 2016
 ************************************************************************/

#include<iostream>

using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() <= 2)
            return points.size();
        int max = 0;
        
        for(int i = 0; i < points.size() - 1; i++)
            for(int j = i + 1; j < points.size(); j++){
                if(isSame(points[i], points[j]))
                    continue;
                else{
                    int on = 2;
                    for(int k = 0; k < points.size(); k++){
                        if(k == i || k == j)
                            continue;
                        if(isSameK(points[i], points[j], points[k]) || isSame(points[i], points[k]) || isSame(points[k], points[j]))
                            on++;
                    }
                    if(on > max)
                        max = on;
                }
            }
        if(max == 0)
            return points.size();
        else
            return max;
    }
private:
    bool isSame(Point a, Point b){
        return a.x == b. x && a.y == b.y;
    }
    
    bool isSameK(Point a, Point b, Point c){
        return (c.x - a.x) * (b.y - a. y) == (b.x - a.x) * (c.y - a.y);
    }
};

class Solution{
public:
    int maxPoints(vector<Point>& points) {
		unordered_map<float,int> slopes;
		int max=0;
		for( int i=points.size()-1 ; i>=max ; i-- ) {
			slopes.clear();
			int m=0,dup=1;
			for( int j=i-1 ; j>=0; j--) {
			    if( points[i].x == points[j].x){
			        if( points[i].y == points[j].y)
				        dup++;
				    else
			            slopes[INT_MAX]++;
			    }else
					slopes[(float)(points[i].y-points[j].y)/(points[i].x-points[j].x)]++;
			}
			for( auto s : slopes)
			    m = m>s.second?m:s.second;
			m += dup;
			max = max>m?max:m;
		}
		return max;
	}
};
