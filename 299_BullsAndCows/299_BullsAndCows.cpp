/*************************************************************************
	> File Name: 299_BullsAndCows.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 21:50:45 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        for(int i = 0; i < secret.size();){
            if(secret[i] == guess[i]){
                bull++;
                secret.erase(secret.begin() + i);
                guess.erase(guess.begin() + i);
            } else i++;
        }
        
        int cow = 0;
        for(int i = 0; i < guess.size();){
            int index = secret.find(guess[i]);
            if(index != string::npos){
                cow++;
                secret.erase(secret.begin() + index);
                guess.erase(guess.begin() + i);
            } else {
                i++;
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};

