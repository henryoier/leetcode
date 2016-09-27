/*************************************************************************
	> File Name: 216_CombinationSumIII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 27 15:37:55 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return dfs(0, k, n);   
    }
private:
    vector<vector<int>> dfs(int last, int k, int n) {
        if(k == 0 && n != 0 || k*(19 - k)/2 < n)
            return vector<vector<int>>();
        if(k == 1)
            return vector<vector<int>>(1, vector<int>(1, n));
            
        vector<vector<int>> result;
        int i = last + 1;
        while((2 * i + k - 1) * k / 2 <= n){
            vector<vector<int>> temp =  dfs(i, k - 1, n - i);
            for(int j = 0; j < temp.size(); j++)
                temp[j].insert(temp[j].begin(), i);
            result.insert(result.end(), temp.begin(), temp.end());
            i++;
        }
        return result;
    }
};

