/*************************************************************************
	> File Name: 036_ValidSudoku.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Aug 28 23:53:18 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {   
        for(int i = 0; i < board.size(); i++){
            bool hash1[10], hash2[10];
            fill(hash1, hash1 + 10, false);
            fill(hash2, hash2 + 10, false);

            for(int j = 0; j < board.size(); j++){
                if(board[i][j] != '.')
                    if(hash1[board[i][j] - '0'])
                        return false;
                    else
                        hash1[board[i][j] - '0'] = true;
                
                if(board[j][i] != '.')
                    if(hash2[board[j][i] - '0'])
                        return false;
                    else
                        hash2[board[j][i] - '0'] = true;
        }    
        
        return check9(board, 0,0,3,3) && check9(board, 0,3,3,6) && check9(board, 0,6,3,9) && check9(board, 3,0,6,3) && check9(board, 3,3,6,6) && check9(board, 3,6,6,9) && check9(board, 6,0,9,3) && check9(board, 6,3,9,6) && check9(board, 6,6,9,9);
    }
private:
    bool check9(vector<vector<char>> board, int x1, int y1, int x2, int y2){
        bool hash[10];
        fill(hash, hash + 10, false);

        for(int i = x1; i < x2; i++)
            for(int j = y1; j < y2; j++)
                if(board[i][j] != '.')
                    if(hash[board[i][j] - '0'])
                        return false;
                    else
                        hash[board[i][j] - '0'] = true;
        return true;
    }    
};

int main() {
    
    return 0;
}
