/*************************************************************************
	> File Name: 310_MinimumHeightTrees.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct 17 20:24:48 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_set<int> nodes;
        unordered_map<int, unordered_set<int>> post;
        
        for(int i = 0; i < n; i++)
            nodes.insert(i);

        for(auto i:edges){
            post[i.first].insert(i.second);
            post[i.second].insert(i.first);
        }
        
        queue<int> del;
        for(int i = 0; i < n; i++)
            if(post[i].size() == 1)
                del.push(i);
        
        while(!del.empty() && nodes.size() > 2){
            int cur = del.size();
            for(int i = 0; i < cur; i++){
                int top = del.front();
                post[*post[top].begin()].erase(top);
                if(post[*post[top].begin()].size() == 1)
                    del.push(*post[top].begin());
                nodes.erase(top);
                del.pop();
            }
        }
        
        vector<int> result;
        for(auto i:nodes)
            result.push_back(i);
        
        return result;
    }
};
