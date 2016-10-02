/*************************************************************************
	> File Name: 392_IsSubsequence.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  1 22:00:03 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_index = 0, t_index = 0;
        return findSequence(s, s_index, t, t_index);
    }
private:
    bool findSequence(string& s, int s_index, string& t, int t_index){
        if(s_index == s.length())
            return true;
        if(t_index >= t.length())
            return false;
            
        int index = t.find(s[s_index], t_index);
        if(index == string::npos)
            return false;
        else
            return findSequence(s, s_index + 1, t, index + 1);
    }
};
