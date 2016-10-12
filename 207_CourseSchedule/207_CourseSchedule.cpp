/*************************************************************************
	> File Name: 207_CourseSchedule.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct 11 21:13:55 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> post(numCourses);
        vector<int> indegree(numCourses);
        
        for(auto i:prerequisites){
            post[i.second].push_back(i.first);
            indegree[i.first]++;
        }
        
        int numSelect = 0;
        queue<int> q;
        for(int i = 0 ; i < numCourses; i++)
            if(indegree[i] == 0){
                q.push(i);
                numSelect++;
            }
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto i:post[cur])
                if(--indegree[i] == 0){
                    q.push(i);
                    numSelect++;
                }
        }
        return numSelect == numCourses;
    }
};
