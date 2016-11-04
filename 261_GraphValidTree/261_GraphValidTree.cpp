/*************************************************************************
	> File Name: 261_GraphValidTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Nov  4 14:18:04 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(edges.size() != n - 1)
            return false;
        vector<int> f(n, 0);
        iota(f.begin(), f.end(), 0);
        
        for(auto edge:edges){
            if(find(f, edge.first) == find(f, edge.second))
                return false;
            union_set(edge.first, edge.second, f);
        }
        return true;
    }
private:
    int find(vector<int> f, int node){
        while(f[node] != node){
            node = f[node] = f[f[node]];
        }
        return node;
    }
    
    void union_set(int nodea, int nodeb, vector<int>& f){
        f[find(f, nodea)] = f[find(f, nodeb)];
    }
};

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        vector<bool> visited(n ,false);
        
        if(edges.size() != n - 1)
            return false;
        for(auto edge : edges){
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
            
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int count = 1;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto next : graph[cur]){
                if(visited[next])
                    return false;
                else {
                    q.push(next);
                    visited[next] = true;
                    count++;
                    graph[next].erase(cur);
                }
            }
        }
        return count == n;
    }
};

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        vector<bool> visited(n ,false);
        for(auto edge : edges){
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
        return edges.size() == n - 1 && dfs(0, graph, visited) == n;
    }
private:
    int dfs(int curNode, unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited){
        if(visited[curNode])
            return 0;
        else {
            int result = 1;
            visited[curNode] = true;
            for(auto next : graph[curNode]){
                graph[next].erase(curNode);
                result += dfs(next, graph, visited);
            }
            return result;
        }
    }
};

