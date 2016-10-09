/*************************************************************************
	> File Name: 320_GeneralizedAbbreviation.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  9 17:17:05 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        return gen(word, false);
    }
private:
    vector<string> gen(string word, bool lastDigit){
        vector<string> result;
        if(word.length() == 0)
            return vector<string>(1, "");
            
        if(lastDigit){
            result = gen(word.substr(1), false);
            for(int i = 0; i < result.size(); i++)
                result[i].insert(0, 1, word[0]);
            return result;
        } else {
            for(int len = 0; len <= word.length(); len++){
                if(len == 0){
                    vector<string> temp = gen(word.substr(1), false);
                    for(int i = 0; i < temp.size(); i++)
                        temp[i].insert(0, 1, word[0]);
                    result.insert(result.end(), temp.begin(), temp.end());
                } else {
                    vector<string> temp = gen(word.substr(len), true);
                    for(int i = 0; i < temp.size(); i++)
                        temp[i].insert(0, to_string(len));
                    result.insert(result.end(), temp.begin(), temp.end());
                }
            }
            return result;
        }
    }
};
