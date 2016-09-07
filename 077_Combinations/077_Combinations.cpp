/*************************************************************************
	> File Name: 077_Combinations.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep  7 13:16:05 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int path[k];
        vector<vector<int> > result;

        dfs(0, 0, n, k, path, result);

        return result;
    }
    
private:
    void dfs(int depth, int last, int n, int k, int path[], vector<vector<int>>& result){
        if(depth == k) {
            vector<int> temp;
            for(int i = 0; i < k; i++)
                temp.push_back(path[i]);
            result.push_back(temp);
            return;
        }
        
        for(int i = last + 1; i <= n - (k - depth - 1); i++){
            path[depth] = i;
            dfs(depth + 1, i, n, k, path, result);
        }   
    }
};

int main() {
    Solution newSolution;
    
    return 0;
}
