/*************************************************************************
	> File Name: 130_SurroundedRegions.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct  5 17:59:15 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return;
            
        int n = board.size(), m = board[0].size();
        
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O')
                floodfill(i, 0, board);
            if(board[i][m - 1] == 'O')
                floodfill(i, m - 1, board);
        }
        for(int j = 1; j + 1 < m; j++){
            if(board[0][j] == 'O')
                floodfill(0, j, board);
            if(board[n - 1][j] == 'O')
                floodfill(n - 1, j, board);
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == '1')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                        board[i][j] = 'X';
    }
private:
    void floodfill(int x, int y, vector<vector<char>>& board){
        board[x][y] = '1';
        if(x + 1 < board.size() && board[x + 1][y] == 'O')
            floodfill(x + 1, y, board);
        if(x - 1 >= 0 && board[x - 1][y] == 'O')
            floodfill(x - 1, y, board);
        if(y + 1 < board[0].size() && board[x][y + 1] == 'O')
            floodfill(x, y + 1, board);
        if(y - 1 >= 0 && board[x][y - 1] == 'O')
            floodfill(x, y - 1, board);
        return;
    }
};
