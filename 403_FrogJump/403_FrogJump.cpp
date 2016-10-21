/*************************************************************************
	> File Name: 403_FrogJump.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct 21 14:24:04 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> last;
        unordered_map<int, int> idx;
        
        for(int i = 0; i < stones.size(); i++)
            idx[stones[i]] = i;
            
        if(stones.empty())
            return true;
        last[0].insert(0);
        
        if(stones[1] == 1)
            last[1].insert(1);
        else    
            return false;
            
        for(int i = 1; i < stones.size() - 1; i++)
            for(step:last[i])
                for(int j = step - 1; j <= step + 1; j++)
                    if(j != 0 && idx.count(stones[i] + j))
                        last[idx[stones[i] + j]].insert(j);

        return last[stones.size() - 1].size() != 0;       
    }
};
