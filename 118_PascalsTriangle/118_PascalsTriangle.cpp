/*************************************************************************
	> File Name: 118_PascalsTriangle.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 20 23:22:38 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 0; i < numRows; i++){
            if(i == 0)
                result.push_back(vector<int>(1, 1));
            else{
                vector<int> temp;
                for(int j = 0; j <= result[i - 1].size(); j++){
                    if(j == 0 || j == result[i - 1].size())
                        temp.push_back(1);
                    else
                        temp.push_back(result[i-1][j] + result[i-1][j-1]);
                }
                result.push_back(temp);
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
