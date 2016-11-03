/*************************************************************************
	> File Name: 010_RegularExpressionMatching.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Aug  3 23:46:44 2016
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p){
        int s_index = 0, p_index = 0;
        return searchMatch(s, s_index, p, p_index);
    }

private:
    bool searchMatch(string s, int s_index, string p, int p_index){
        if(s_index == s.size())
            if(p_index == p.size())
                return true;
            else {
                if(p[p_index] == '*')
                    return searchMatch(s, s_index, p, p_index + 1);
                else if(p_index < p.size() - 1 && p[p_index + 1] == '*')
                        return searchMatch(s, s_index, p, p_index + 2);
                    else
                        return false;
            }
        else{
           if(p_index < p.size() - 1 && p[p_index + 1] == '*')
                if(s[s_index] == p[p_index] || p[p_index] == '.')
                    return searchMatch(s, s_index + 1, p, p_index) || searchMatch (s, s_index, p, p_index + 2);
                else
                    return searchMatch(s, s_index, p, p_index + 2);
            else
                if(s[s_index] == p[p_index] || p[p_index] == '.')
                    return searchMatch(s, s_index + 1, p, p_index + 1);
                else
                    return false;
        }
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> f(2, vector<bool>(m + 1, false));
        f[0][0] = true;
        for(int j = 0; j < m; j++)
            if(p[j] == '*')
                f[0][j + 1] = f[0][j - 1];
        
        for(int i = 1; i <= n; i++){
            f[i % 2][0] = false;
            for(int j = 1; j <= m; j++)
                if(p[j - 1] == '*')
                    f[i % 2][j] = f[i % 2][j - 2] || (f[(i + 1) % 2][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                else
                    if(p[j - 1] == '.' || (s[i - 1] == p[j - 1]))
                        f[i % 2][j] = f[(i + 1)%2][j - 1];
                    else
                        f[i % 2][j] = false;
        }
        return f[n % 2][m];
    }
};

int main(){
    string s,p;
    cin >> s >> p;

    Solution newSolution;
    cout << newSolution.isMatch(s, p) <<endl;
    return 0;
}
