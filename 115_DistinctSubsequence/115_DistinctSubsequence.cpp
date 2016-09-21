/*************************************************************************
	> File Name: 115_DistinctSubsequence.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 20 22:10:14 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        
        vector<vector<int> > f(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 0; i <= m; i++)
            f[i][0] = 1;
            
        for(int j = 1; j <= n; j++){
            for(int i = j; i <= m; i++){
                if(s[i - 1] == t[j - 1])
                    f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
                else
                    f[i][j] = f[i - 1][j];
            }
        }
        return f[m][n];
    }
};

int main() {
    return 0;
}
