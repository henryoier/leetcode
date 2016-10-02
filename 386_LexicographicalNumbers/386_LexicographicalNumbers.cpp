/*************************************************************************
	> File Name: 386_LexicographicalNumbers.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  1 23:33:27 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> num;
        dfs(0, n, num);
        return num;
    }
private:
    void dfs(int now, int n, vector<int>& num){
        if(now != 0){
            num.push_back(now);
            if(now * 10 <= n)
                dfs(now * 10, n, num);
        }
        for(int i = 1; i < 10 && now + i <= n; i++){
            num.push_back(now + i);
            if((now + i) * 10 <= n)
                dfs((now + i) * 10, n, num);
        }
    }
};
