/*************************************************************************
	> File Name: 277_FindTheCelebrity.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  8 21:51:34 2016
 ************************************************************************/

#include<iostream>

using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> know;
        for(int i = 0; i < n; i++){
            bool known = false;
            for(int j = 0; j < n; j++)
                if(i != j && knows(i, j)){
                    known = true;
                    break;
                }
            if(!known)
                know.push_back(i);
        }
        
        if(know.size() == 0)
            return -1;
        else{
            for(int cel = 0; cel < know.size(); cel++){
                bool allKnow = true;
                for(int i = 0; i < n; i++)
                    if(i != know[cel])
                        if(knows(i, know[cel])){
                        } else {
                            allKnow = false;
                            break;
                        }
                if(allKnow)
                    return know[cel];
            }
            return -1;
        }
    }
};
