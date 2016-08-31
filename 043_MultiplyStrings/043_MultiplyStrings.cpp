/*************************************************************************
	> File Name: 043_MultiplyStrings.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Aug 31 10:12:57 2016
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int length = num1.size() + num2.size();
        int n1[num1.size()], n2[num2.size()];
        int mulResult[length];

        fill(mulResult, mulResult + length, 0);

        for(int i = 0; i < num1.size();i++)
            n1[i] = num1[i] - '0';
        for(int i = 0; i < num2.size();i++)
            n2[i] = num2[i] - '0';

        for(int i = 0; i < num1.size(); i++){
            for(int j = 0; j < num2.size(); j++){
                mulResult[i + j] += n1[i] * n2[j] % 10;
                mulResult[i + j + 1] += n1[i] * n2[j] / 10;
            }
        }
        
        for(int i  = 0; i < length - 1; i++){
            if(mulResult[i] > 9) {
                mulResult[i + 1] += mulResult[i] / 10;
                mulResult[i] = mulResult[i] % 10 ; 
            }
        }
        
        string result;
        
        for(int i = 0; i < length; i++)
            result += mulResult[i] + '0';

        while(result[result.size() - 1] == '0' && result.size() > 1)
            result.erase(result.end() - 1);
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution newSolution;

    cout << newSolution.multiply("99999999","99") << endl;

    return 0;
}
