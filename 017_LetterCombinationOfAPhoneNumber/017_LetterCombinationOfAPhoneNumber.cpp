/*************************************************************************
	> File Name: 017_LetterCombinationOfAPhoneNumber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Aug  5 22:11:34 2016
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const vector<string> keyboard = {" ", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        char result[digits.length()];
        vector<string> finalResult;
        if(digits.length() == 0)
            return finalResult;
        dfs(digits, 0, keyboard, result, finalResult);

        return finalResult;
    }

private:
    void dfs(string digits, int depth, const vector<string> keyboard, char *result, vector<string>& finalResult){
        if(digits.length() == depth){
            string tempResult = "";
            for(int i = 0; i < depth; i++)
                tempResult = tempResult + result[i];
            finalResult.push_back(tempResult);
            return;
        }
        
        for(int i = 0; i < keyboard[digits[depth]  - '0'].size();i++){
            result[depth] = keyboard[digits[depth] - '0'][i];
            dfs(digits, depth + 1, keyboard, result, finalResult);
        }
        return;
    }
};

int main(){
    Solution newSolution;
    vector<string> finalResult = newSolution.letterCombinations("23");

    for(int i = 0; i < finalResult.size(); i++)
        cout << finalResult[i] <<endl;

    return 0;
}
