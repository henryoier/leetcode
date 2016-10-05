/*************************************************************************
	> File Name: 345_ReverseVowelsOfAString.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct  4 23:41:54 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        if(s.length() < 2)
            return s;
            
        unordered_set<char> vowel({'A','E','I','O','U','a','e','i','o','u'});
        
        int head = 0, tail = s.length() - 1;
        while(head < tail){
            while(vowel.find(s[head]) == vowel.end() && head < s.length()) head++;
            while(vowel.find(s[tail]) == vowel.end() && tail >= 0) tail--;
            
            if(head < tail){
                swap(s[head], s[tail]);
                head++;
                tail--;
            }
        }
        
        return s;
    }
};
