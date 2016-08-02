/*************************************************************************
	> File Name: 008_StringToInteger.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Aug  2 22:16:08 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        bool negative = false;
        while(str[0] == ' ')
            str = str.substr(1);

        if(str[0] != '+' && str[0] != '-' && !(str[0] >= '0' && str[0] <= '9'))
            return 0;

        if(str[0] == '+' || str[0] == '-'){
            if(str[0] == '-')
                negative = !negative;
            str = str.substr(1);
        }

        if(!(str[0]>='0' && str[0] <= '9'))
            return 0;

        for(int i = 0; i < str.length(); i++){
            if(str[i] >= '0' && str[i] <= '9'){
                result = result * 10 + (str[i] - '0');
                if(result > INT_MAX && !negative){
                    result = INT_MAX;
                    break;
                }
                if(0 - result < INT_MIN && negative){
                    result = 0 - INT_MIN;
                    break;
                }
            } else
                break;
        }
        if(negative)
            return 0 - result;
        else
            return result;
    }
};

int main(){
    string str;

    getline(cin, str);

    Solution newSolution;

    cout << newSolution.myAtoi(str);
}
