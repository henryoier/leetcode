/*************************************************************************
	> File Name: 289_GameOfLife.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 16:14:25 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return;
        int n = board.size(), m = board[0].size();
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                int num = getState(i, j, board);
                
                if(num < 2 && board[i][j] == 1)
                    board[i][j] = 1;
                else if(num >= 2 && num <=3 && board[i][j] == 1)
                    board[i][j] = 3;
                else if(num > 3 && board[i][j] == 1)
                    board[i][j] = 1;
                else if(num == 3 && board[i][j] == 0)
                    board[i][j] = 2;
                else
                    board[i][j] = 0;
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                board[i][j] = (board[i][j] >> 1);
    }
private:
    int getState(int i, int j, vector<vector<int>> board){
        int result = 0;
        for(int newi = i - 1; newi <= i + 1; newi++)
            for(int newj = j - 1; newj <= j + 1; newj++){
                if(newi == i && newj == j)
                    {}
                else
                    if(newi < 0 || newj < 0 || newi == board.size() || newj == board[0].size())
                        {}
                    else    
                        result += (board[newi][newj] & 1);
            }
        return result;
    }
};

