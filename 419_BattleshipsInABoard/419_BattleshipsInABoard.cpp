/*************************************************************************
	> File Name: 419_BattleshipsInABoard.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct 21 13:10:51 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return 0;
        int n = board.size(), m = board[0].size();
        int count = 0;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == 'X'){
                    unordered_set<int> x_cor;
                    unordered_set<int> y_cor;
                    dfs(i, j, board, x_cor, y_cor);
                    if(min(x_cor.size(), y_cor.size()) == 1)
                        count += 1;
                }
        return count;
                  
    }
private:
    void dfs(int x, int y, vector<vector<char>>& board, unordered_set<int>& x_cor, unordered_set<int>& y_cor){
        x_cor.insert(x);
        y_cor.insert(y);
        board[x][y] = '.';
        if(x > 0 && board[x - 1][y] == 'X')
            dfs(x - 1, y, board, x_cor, y_cor);
        if(x < board.size() - 1 && board[x + 1][y] == 'X')
            dfs(x + 1, y, board, x_cor, y_cor);
        if(y > 0 && board[x][y - 1] == 'X')
            dfs(x, y - 1, board, x_cor, y_cor);
        if(y < board[0].size() && board[x][y + 1] == 'X')
            dfs(x, y + 1, board, x_cor, y_cor);
    }
};
