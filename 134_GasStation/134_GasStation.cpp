/*************************************************************************
	> File Name: 134_GasStation.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct  5 20:07:57 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> remain;
        vector<int> start;
        for(int i = 0; i < gas.size(); i++){
            remain.push_back(gas[i] - cost[i]);
            if(i != 0 && remain[i] >= 0 && remain[i - 1] < 0)
                start.push_back(i);
        }
        if(*remain.begin() >= 0 && *prev(remain.end()) < 0)
            start.push_back(0);
            
        if(remain.size() == 1)
            if(remain[0] < 0)
                return -1;
            else
                return 0;
            
        for(auto s:start){
            int i = s;
            int total = 0;
            while(true){
                total += remain[i];
                if(total < 0)
                    break;
                else{
                    i = (i + 1) % remain.size();
                    if(i == s)
                        return s;
                }
            }
        }
        return -1;
    }
};
