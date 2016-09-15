/*************************************************************************
	> File Name: 079_WordSearch.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 12 00:43:45 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0)
            return false;
        
        int n = board.size(), m = board[0].size();
        
        vector<vector<bool> > used(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++)   
            for(int j = 0; j < m; j++)
                if(dfs(0, i, j, word, board, used))
                    return true;
                    
        return false;
    }

private:
    static bool dfs(int depth, int i, int j, string word, vector<vector<char>> board, vector<vector<bool>>& used){
        if(depth == word.length())
            return true;
        if(i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] != word[depth] || used[i][j])
            return false;
        else {
            used[i][j] = true;    
            bool result = dfs(depth + 1, i + 1, j, word, board, used) ||
                            dfs(depth + 1, i - 1, j, word, board, used) ||
                                dfs(depth + 1, i, j + 1, word, board, used) ||
                                    dfs(depth + 1, i, j - 1, word, board, used);
            used[i][j] = false;
            return false;
        }
    }
};

int main() {
    return 0;
}
