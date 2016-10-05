/*************************************************************************
	> File Name: 037_SudokuSolver.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Aug 30 21:10:07 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> used_row(9, vector<bool>(10, false)), used_column(9, vector<bool>(10, false)), used_area(9, vector<bool>(10, false));
        
        bool find = false;

        for(int i  = 0; i < 9; i++)
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    used_row[i][board[i][j] - '0'] = true;
                    used_column[j][board[i][j] - '0'] = true;
                    used_area[i/3*3 + j/3][board[i][j] - '0'] = true;
                }
            }
    
        dfs(board, used_row, used_column, used_area, 0, 0, find);
        return;
    }
private:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& used_row, vector<vector<bool>>& used_column, vector<vector<bool>>& used_area, int i, int j, bool& find){
        if(i == 9){
            find = true;
            return;
        }
        if(board[i][j] == '.'){
            for(int num = 1; num < 10; num++)
                if(!used_row[i][num] && !used_column[j][num] && !used_area[i/3*3 + j/3][num]){
                    board[i][j] = num + '0';
                    used_row[i][num] = true;
                    used_column[j][num] = true;
                    used_area[i/3*3 + j/3][num] = true;

                    dfs(board, used_row, used_column, used_area, i + (j + 1)/9, (j + 1) % 9, find);
                    
                    if(find)
                        return;
                    else{
                        board[i][j] = '.';
                        used_row[i][num] = false;
                        used_column[j][num] = false;
                        used_area[i/3*3 + j/3][num] = false;
                    }
                    
                }
                else {}
        } 
        else
            dfs(board, used_row, used_column, used_area, i + (j + 1)/9, (j + 1) % 9, find);
            
        return;
    }
};
