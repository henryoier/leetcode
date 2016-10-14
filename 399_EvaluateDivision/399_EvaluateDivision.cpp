/*************************************************************************
	> File Name: 399_EvaluateDivision.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct 14 16:03:59 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, int> idx;
        
        int n = 0;
        for(int i = 0; i < equations.size(); i++){
            string a = equations[i].first;
            if(!idx.count(a)){
                idx[a] = n;
                n++;
            }
            string b = equations[i].second;
            if(!idx.count(b)){
                idx[b] = n;
                n++;
            }
        }
        
        vector<vector<double>> map(n, vector<double>(n, INT_MAX));
        
        for(int i = 0; i < equations.size(); i++){
            string a = equations[i].first;
            string b = equations[i].second;
            map[idx[a]][idx[b]] = values[i];
            map[idx[a]][idx[a]] = 1.0; 
            if(values[i] != 0){
                map[idx[b]][idx[a]] = 1 / values[i];
                map[idx[b]][idx[b]] = 1.0;
            }
        }
        
        for(auto i:idx){
            int cur = i.second;
            queue<int> q;
            vector<bool> visited(n, false);
            
            q.push(cur);
            visited[cur] = true;
            
            while(!q.empty()){
                int now = q.front();
                q.pop();
                
                for(auto j:idx){
                    if(!visited[j.second] && map[now][j.second] != INT_MAX){
                        map[cur][j.second] = map[cur][now] * map[now][j.second];
                        q.push(j.second);
                        visited[j.second] = true;
                    }
                }
            }
        }
        
        /*for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << map[i][j] << ' ';
            cout << endl;
        }*/
        
        vector<double> result;
        for(auto i:queries){
            if(!idx.count(i.first) || !idx.count(i.second) || map[idx[i.first]][idx[i.second]] == INT_MAX)
                result.push_back(-1);
            else
                result.push_back(map[idx[i.first]][idx[i.second]]);
        }
        
        return result;
    }
};
