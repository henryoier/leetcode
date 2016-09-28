/*************************************************************************
	> File Name: 402_RemoveKDigits.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 28 18:53:50 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k > 0){
            int i;
            for(i = 0; i < num.size() - 1;i++){
                if(num[i] > num[i + 1])
                    break;
            }
            num.erase(num.begin() + i);
            k--;
        } 
        while(num[0] == '0')
            num.erase(num.begin());
            
        if(num.empty())
            return "0";
        else
            return num;
    }
};
