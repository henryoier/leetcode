/*************************************************************************
	> File Name: 322_CoinChange.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct  3 22:33:44 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
            
        queue<pair<int, int>> q;
        unordered_set<int> hash;
        
        q.push(pair<int, int>(0, 0));
        
        while(!q.empty()){
            int now = q.front().first;
            int step = q.front().second;
            
            q.pop();
            for(auto i:coins){
                if(now + i <= amount && hash.find(now + i) == hash.end())
                    if(now + i == amount)
                        return step + 1;
                    else{
                        hash.insert(now + i);
                        q.push(pair<int, int>(now + i, step + 1));
                    }
            }
        }
        return -1;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, 0);
        f[0] = 0;
        
        for(int i = 1; i <= amount; i++){
            f[i] = INT_MAX;
            for(auto j:coins){
                if(i - j >= 0 && f[i - j] != INT_MAX && f[i - j] + 1 < f[i])
                    f[i] = f[i - j] + 1;
            }
        }
        
        if(f[amount] == INT_MAX)
            return -1;
        else
            return f[amount];
    }
};
