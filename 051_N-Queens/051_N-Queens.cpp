/*************************************************************************
	> File Name: 051_N-Queens.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep  1 22:31:42 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        int path[n];
        vector<vector<string>> result;
        dfs(0, n, path, result);
        
        return result;
    }

private:
    void dfs(int depth, int n, int path[], vector<vector<string>>& result){
        if(depth == n){
            vector<string> temp;
            for(int i = 0; i < n; i++){
                string row(n, '.');
                row[path[i]] = 'Q';
                temp.push_back(row);
            }
            result.push_back(temp);
        }
        
        for(int i = 0; i < n; i++){
            if(checkLegal(depth, i, path)){
                path[depth] = i;
                dfs(depth + 1, n, path, result);
            }
        }
    }

    bool checkLegal(int depth, int i, int path[]){
        for(int j = depth - 1; j >= 0; j--){
            if(path[j] == i || abs(i - path[j]) == abs(depth - j))
                return false;
        }
        return true;
    }   
};

int main() {

}
