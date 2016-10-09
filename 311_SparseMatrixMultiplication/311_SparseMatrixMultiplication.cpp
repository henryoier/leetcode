/*************************************************************************
	> File Name: 311_SparseMatrixMultiplication.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  9 16:36:26 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size(), p = B[0].size();
        vector<vector<int>> result(m, vector<int>(p, 0));
        
        map<int, map<int, int>> A_s, B_s;
        
        for(int i = 0; i < m; i++){
            map<int, int> temp;
            for(int j = 0; j < n; j++)
                if(A[i][j] != 0)
                    temp[j] = A[i][j];
            if(temp.size() != 0)
                A_s[i] =temp;
        }
        
        for(int i = 0; i < p; i++){
            map<int, int> temp;
            for(int j = 0; j < n; j++)
                if(B[j][i] != 0)
                    temp[j] = B[j][i];
            if(temp.size() != 0)
                B_s[i] = temp;
        }
            
        
        for(auto k1 = A_s.begin(); k1 != A_s.end(); k1++)
            for(auto k2 = B_s.begin(); k2 != B_s.end(); k2++){
                auto s1 = k1->second.begin();
                auto s2 = k2->second.begin();
                while(s1 != k1->second.end() && s2 != k2->second.end()){
                    if(s1->first < s2->first)
                        s1 = next(s1);
                    else if(s1->first > s2->first)
                        s2 = next(s2);
                    else{
                        result[k1->first][k2->first] += s1->second * s2->second;
                        s1 = next(s1);
                        s2 = next(s2);
                    }
                }
            }
        return result;
    }
};
