/*************************************************************************
	> File Name: 323_NumberOfConnectedComponentsInAnUndirectedGraph.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  9 17:34:14 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        
        for(auto edge:edges){
            int i = edge.first, j = edge.second;
            while(p[i] != i) i = p[i] = p[p[i]];
            while(p[j] != j) j = p[j] = p[p[j]];
            
            n -= p[i] != p[j];
            p[i] = p[j];
        }
        return n;
    }
};
