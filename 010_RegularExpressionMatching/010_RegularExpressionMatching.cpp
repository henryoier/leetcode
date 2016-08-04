/*************************************************************************
	> File Name: 010_RegularExpressionMatching.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Aug  3 23:46:44 2016
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_index = 0, p_index = 0;
        while(s_index < s.size() && p_index < p.size()){
            if(p[p_index] == '.'){
                p_index++;
                s_index++;
            } else if(p[p_index] == '*' && p_index > 0 && s_index > 0){
                if(s[s_index] == s[s_index - 1] || p[p_index - 1] == '.'){
                    s_index++;
                } else if (p_index < p.size() - 1 && (p[p_index + 1] == s[s_index] || p[p_index + 1] == '.')){
                    s_index++;
                    p_index += 2;
                }
            } else if (p[p_index] == s[s_index]){
                s_index++;
                p_index++;
            } else if(p_index < p.size() - 1 && p[p_index + 1] == '*'){
                p_index += 2;
            } else break;
        }
        p = p.substr(p_index);
        while(p.find_first_of('*') == 0 || p.find_first_of('*') == 1){
            p = p.substr(p.find_first_of('*') + 1);
        }
        if(s_index == s.size() && p.length() == 0)
            return true;
        else
            return false;
    }
};
*/

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

int main(){
    string s,p;
    cin >> s >> p;

    Solution newSolution;
    cout << newSolution.isMatch(s, p) <<endl;
    return 0;
}
