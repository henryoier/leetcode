/*************************************************************************
	> File Name: 003_LongestSubstringWithoutRepeatingCharacters.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Jul 26 16:43:09 2016
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return s.length();
    }
};

int main(){

    Solution newSolution;
    string s;

    cin >> s;
    cout << newSolution.lengthOfLongestSubstring(s) << endl;

    return 0;
}
