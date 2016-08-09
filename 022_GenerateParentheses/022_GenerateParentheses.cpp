/*************************************************************************
	> File Name: 022_GenerateParentheses.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Aug  8 00:22:48 2016
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        char *resultChar = new char[n * 2];
        getParenthesis(n, 0, 0, resultChar, result);
        
        //sort(result.begin(), result.end());
        //vector<string>::iterator end_unique = unique(result.begin(), result.end());
        //result.erase(end_unique, result.end());
        return result;
    }
    
private:
    void getParenthesis(int n, int pos, int leftn, char *resultChar, vector<string>& result){
        if(pos == n * 2 && leftn == 0){
            string tempResult;
            for(int i = 0; i < n * 2; i++){
                tempResult += resultChar[i];
            }
            result.push_back(tempResult);
            return;
        }

        if(leftn == 0){
            resultChar[pos] = '(';
            getParenthesis(n, pos + 1, leftn + 1, resultChar, result);
        } else {
            if(n * 2 - pos > leftn){
                resultChar[pos] = '(';
                getParenthesis(n, pos + 1, leftn + 1, resultChar, result);

                resultChar[pos] = ')';
                getParenthesis(n, pos + 1, leftn - 1, resultChar, result);
            } else {
                resultChar[pos] = ')';
                getParenthesis(n, pos + 1, leftn - 1, resultChar, result);
            }
        }    
    }
};

int main(){
    int n;
    Solution newSolution;

    cin >> n;
    
    vector<string> result = newSolution.generateParenthesis(n);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;

    return 0;
}
