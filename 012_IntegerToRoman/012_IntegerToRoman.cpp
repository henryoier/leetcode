/*************************************************************************
	> File Name: 012_IntegerToRoman.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Aug  5 00:05:47 2016
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        char Roman[4][2] = {{'I','V'},{'X','L'},{'C','D'},{'M','#'}};
        string result;
        int pos = 0;
        while(num > 0){
            int digit = num % 10;
            if(digit < 4)
                while(digit > 0){
                    result = Roman[pos][0] + result;
                    digit--;
                }
            else if (digit >= 5 && digit < 9){
                while(digit > 5){
                    result = Roman[pos][0] + result;
                    digit--;
                }
                result = Roman[pos][1] + result;
            } else if(digit == 4){
                result = Roman[pos][1] + result;
                result = Roman[pos][0] + result;
            } else if(digit == 9){
                result = Roman[pos + 1][0] + result;
                result = Roman[pos][0] + result;
            }
            num = num / 10;
            pos++;
        }
        return result;
    }
};

int main(){
    int num;
    Solution newSolution;

    cin >> num;
    cout << newSolution.intToRoman(num) << endl;
    return 0;
}
