/*************************************************************************
	> File Name: 254_FactorCombinations.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 22:17:49 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        for(int i = 2; i * i <= n ; i++){
            if(n % i == 0){
                vector<vector<int>> temp = getF(n / i, i);
                for(int j = 0; j < temp.size(); j++)
                    temp[j].insert(temp[j].begin(), i);
                result.insert(result.end(), temp.begin(), temp.end());
            }
        }   
        return result;
    }
private:
    vector<vector<int>> getF(int n, int last){
        vector<vector<int>> result;
        result.push_back(vector<int>(1, n));
        for(int i = last; i * i <= n ; i++){
            if(n % i == 0){
                vector<vector<int>> temp = getF(n / i, i);
                for(int j = 0; j < temp.size(); j++)
                    temp[j].insert(temp[j].begin(), i);
                result.insert(result.end(), temp.begin(), temp.end());
            }
        }
        return result;
    }
};
