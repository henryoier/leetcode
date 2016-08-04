/*************************************************************************
	> File Name: 014_LongestCommonPrefix.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Aug  5 00:33:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        for(int i = 0; i < strs[0].size(); i++){
            bool flag = true;  
            char commonChar = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != commonChar || i == strs[j].size()){
                    flag = false;
                    break;
                }
            }
            if(flag == false)
                return strs[0].substr(0, i);
        }
        return strs[0];
    }
};

int main(){
    string a[3] = {"abc","abc","abcde"};
    vector<string> strs(a, a+3);
    Solution newSolution;

    cout << newSolution.longestCommonPrefix(strs) << endl;
    return 0;
}
