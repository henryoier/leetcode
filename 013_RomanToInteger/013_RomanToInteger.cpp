/*************************************************************************
	> File Name: 013_RomanToInteger.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Aug  5 14:39:31 2016
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> Roman = {{'I', 1},{'V', 5},{'X', 10},{'L', 50}, {'C', 100}, {'D', 500},{'M', 1000}};
        return getNum(s, Roman);
    }

private:
    int getNum(string s, map<char, int> Roman) {
        int num;
        if(s.size() == 0)
            return 0;
        if(s.size() > 1 && Roman[s[0]] < Roman[s[1]])
            return Roman[s[1]] - Roman[s[0]] + getNum(s.substr(2), Roman);
        else
            return Roman[s[0]] + getNum(s.substr(1), Roman);
    }
};


int main(){
    string s;
    cin >> s;
    Solution newSolution;

    cout << newSolution.romanToInt(s) << endl;
    return 0;
}
