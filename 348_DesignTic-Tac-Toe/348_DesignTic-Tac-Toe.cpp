/*************************************************************************
	> File Name: 348_DesignTic-Tac-Toe.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  9 22:11:33 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rowN.resize(2);
        colN.resize(2);
        diag.resize(2);
        size = n;  
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        rowN[player - 1][row]++;
        if(rowN[player - 1][row] == size)
            return player;
            
        colN[player - 1][col]++;
        if(colN[player - 1][col] == size)
            return player;
            
        if(row == col){
            diag[player - 1][0]++;
            if(diag[player - 1][0] == size)
                return player;
        }
        if(row + col == size - 1){
            diag[player - 1][1]++;
            if(diag[player - 1][1] == size)
                return player;
        }
        return 0;
    }
private:
    vector<unordered_map<int, int>> rowN;
    vector<unordered_map<int, int>> colN;
    vector<unordered_map<int, int>> diag;
    
    int size;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
