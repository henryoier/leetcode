/*************************************************************************
	> File Name: 052_N-QueensII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep  2 01:09:08 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int path[n];
        int result = 0;

        dfs(0, n, path, result);
        
        return result;
    }

private:
    void dfs(int depth, int n, int path[], int& result){
        if(depth == n)
            result++;
        
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

int main(){
    Solution newSolution;
    cout << newSolution.totalNQueens(4) << endl;
    return 0;
}
