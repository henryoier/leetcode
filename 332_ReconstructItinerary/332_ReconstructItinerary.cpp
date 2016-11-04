/*************************************************************************
	> File Name: 332_ReconstructItinerary.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Nov  3 22:36:18 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto ticket : tickets)
            targets[ticket.first][ticket.second]++;
            
        pathLength = tickets.size();
        route = vector<string>(pathLength + 1);
        
        visit("JFK", 0);
        
        return route;
    }
    
private:
    unordered_map<string, map<string, int>> targets;
    vector<string> route;
    int pathLength;
    
    bool visit(string airport, int depth) {
        if(depth == pathLength){
            route[depth] = airport;
            return true;
        }
        /*
        cout << airport <<  ' ' << depth << ' ';
        for(auto& city : targets[airport]){
            cout << city.first << ' ' << city.second << ' ';
        }
        cout << endl;*/
        
        route[depth] = airport;

        for(auto& city : targets[airport]){
            if(city.second > 0){
                --city.second;
                if(visit(city.first, depth + 1))
                    return true;
                ++city.second;
            }
        }
        return false;
    }
};
