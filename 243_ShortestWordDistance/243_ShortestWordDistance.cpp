/*************************************************************************
	> File Name: 243_ShortestWordDistance.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 14:26:33 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int last1 = -1, last2 = -1, min = INT_MAX;
        
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1)
                if(last2 != -1){
                    if(i - last2 < min)
                        min = i - last2;
                    last1 = i;
                } else 
                    last1 = i;
            if(words[i] == word2)
                if(last1 != -1){
                    if(i - last1 < min)
                        min = i - last1;
                    last2 = i;
                } else 
                    last2 = i;
        }
        return min;
    }
};
