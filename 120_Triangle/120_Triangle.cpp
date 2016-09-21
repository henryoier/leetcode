/*************************************************************************
	> File Name: 120_Triangle.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 20 23:55:48 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0)
            return 0;
            
        int minN = INT_MAX;
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= i; j++){
                if(i == 0){}
                else        
                    if(j > 0 && j < i)
                        triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                    else if(j == 0)
                            triangle[i][j] += triangle[i - 1][j];
                        else
                            triangle[i][j] += triangle[i - 1][j - 1];
            
                if(i == n - 1)
                    if(triangle[i][j] < minN)
                        minN = triangle[i][j];
            } 
        return minN;
    }
};

int main() {
    return 0;
}
