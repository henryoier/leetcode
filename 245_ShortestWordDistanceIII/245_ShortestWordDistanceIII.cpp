/*************************************************************************
	> File Name: 245_ShortestWordDistanceIII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 16:15:19 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if(word1 == word2){
            int lastPos = -1, min = INT_MAX;
            for(int i = 0; i < words.size(); i++){
                if(words[i] == word1)
                    if(lastPos == -1)
                        lastPos = i;
                    else{
                        if(i - lastPos < min)
                            min = i - lastPos;
                        lastPos = i;
                    }
            }
            return min;
        } else {
            int lastPos1 = -1, lastPos2 = -1, min = INT_MAX;
            for(int i = 0; i < words.size(); i++){
                if(words[i] == word1){
                    if(lastPos2 == -1)
                        lastPos1 = i;
                    else{
                        if(i - lastPos2 < min)
                            min = i - lastPos2;
                        lastPos1 = i;
                    }
                } 
                if(words[i] == word2) {
                    if(lastPos1 == -1)
                        lastPos2 = i;
                    else{
                        if(i - lastPos1 < min)
                            min = i - lastPos1;
                        lastPos2 = i;
                    }
                }
            }
            return min;
        }
    }
};
