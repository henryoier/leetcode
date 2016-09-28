/*************************************************************************
	> File Name: 405_ConvertANumberToHexadecimal.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 28 16:28:58 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        string result;
        bool neg = num < 0;
        
        for(int i = 0; i < 8; i++){
            int now = num & 15;
            if(now < 10)
                result = (char)(now + '0') + result;
            else
                result = (char)(now - 10 + 'a') + result;
                
           
            num = num >> 4;
          
        }
        while(result[0] == '0' && result.length() != 1)
            result = result.substr(1);
        return result;
    }
};

