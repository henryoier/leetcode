/*************************************************************************
	> File Name: 383_RansomNote.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  1 23:57:30 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_set<char> found;
        for(auto i:ransomNote){
            if(found.find(i) == found.end()){
                if(count(magazine.begin(), magazine.end(), i) < count(ransomNote.begin(), ransomNote.end(), i))
                    return false;
                found.insert(i);
            }
        }
        return true;
    }
};
