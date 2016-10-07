/*************************************************************************
	> File Name: 244_ShortestWordDistanceII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 14:50:44 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); i++)
            pos[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        vector<int> pos1 = pos[word1];
        vector<int> pos2 = pos[word2];
        int min = INT_MAX;
        for(int i = 0, j = 0; i < pos1.size() && j < pos2.size(); ){
            if(abs(pos1[i] - pos2[j]) < min)
                min = abs(pos1[i] - pos2[j]);
            if(pos1[i] < pos2[j])
                i++;
            else
                j++;
        }
        return min;
    }
private:
    unordered_map<string, vector<int>> pos;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
