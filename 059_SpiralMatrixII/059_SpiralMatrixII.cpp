/*************************************************************************
	> File Name: 059_SpiralMatrixII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep  2 21:16:15 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int resultTemp[n * n];
        bool used[n * n];
        
        fill(used, used + n * n, false);

        dfs(0,0,1,n,0,used, resultTemp);
        
        vector<vector<int>> result;
        for(int i = 0; i < n; i++){
            vector<int> temp(resultTemp + n * i, resultTemp + n*(i + 1));
            result.push_back(temp);
        }
        return result;
    }
private:
    void dfs(int x, int y, int i, int n, int pos, bool *used, int *result){
        if(i == n*n + 1)
            return;
        
        result[x*n + y] = i;
        used[x*n + y] = true;

        if(pos == 0){
            if(y + 1 == n || used[x * n + y + 1])
                dfs(x + 1, y, i + 1, n, (pos + 1) % 4, used, result);
            else
                dfs(x, y + 1, i + 1, n, pos, used, result);
        }

        if(pos == 1){
            if(x + 1 == n || used[(x+ 1) * n + y])
                dfs(x, y - 1, i + 1, n, (pos + 1) % 4, used, result);
            else
                dfs(x + 1, y, i + 1, n, pos, used, result);
        }

         if(pos == 2){
            if(y == 0 || used[x *n + y - 1])
                dfs(x - 1, y, i + 1, n, (pos + 1) % 4, used, result);
            else
                dfs(x, y - 1, i + 1, n, pos, used, result);
        }

         if(pos == 3){
            if(x == 0 || used[(x - 1) * n + y])
                dfs(x, y + 1, i + 1, n, (pos + 1) % 4, used, result);
            else
                dfs(x - 1, y, i + 1, n, pos, used, result);
        }
        
    }
};

int main() {
    Solution newSolution;
    vector<vector<int>> result = newSolution.generateMatrix(5);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
