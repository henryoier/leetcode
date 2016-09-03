/*************************************************************************
	> File Name: 058_LengthOfLastWord.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep  2 20:48:55 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 0)
            return 0;
        
        while(s[s.length() - 1] == ' ')
            s.erase(s.length() - 1);
   
        while(s.find(' ') != -1)
            s = s.substr(s.find(' ') + 1);
        
        return s.length();
    }
};

int main() {
    Solution newSolution;

    cout << newSolution.lengthOfLastWord("Hello world") <<endl;

    return 0;
}
