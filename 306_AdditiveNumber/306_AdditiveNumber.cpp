/*************************************************************************
	> File Name: 306_AdditiveNumber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 23:30:21 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int len1 = 1; len1 * 2 < num.length(); len1++){
            if(len1 > 1 && num[0] == '0')
                break;
            for(int len2 = 1; len1 * 2 + len2 <= num.length() && len2 * 2 + len1 <= num.length(); len2++){
                
                string a = num.substr(0, len1);
                string b = num.substr(len1, len2);
                
                if(len2 > 1 && b[0] == '0')
                    break;
                
                string c = to_string(stol(a) + stol(b));
                string result = a + b + c;
                a = b; b = c;
                cout << result << endl;
                
                while(result.length() < num.length()){
                    if(num.find(result) != 0)
                        break;
                    else{
                        c = to_string(stol(a) + stol(b));
                        result = result + c;
                        a = b;
                        b = c;
                    }
                }
                if(result == num)
                    return true;
            }
        }
        return false;
    }
};
