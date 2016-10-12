/*************************************************************************
	> File Name: 210_CourseScheduleII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct 11 21:21:34 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        vector<vector<int> > post(numCourses);
        vector<int> indegree(numCourses);
        
        for(auto i:prerequisites){
            post[i.second].push_back(i.first);
            indegree[i.first]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0)
                q.push(i);
                
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            result.push_back(cur);
            for(auto i:post[cur]){
                if(--indegree[i] == 0)
                    q.push(i);
            }
        }
        
        if(result.size() == numCourses)
            return result;
        else
            return vector<int>();
    }
};
