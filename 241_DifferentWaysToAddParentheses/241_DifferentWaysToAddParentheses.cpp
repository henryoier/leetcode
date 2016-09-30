/*************************************************************************
	> File Name: 241_DifferentWaysToAddParentheses.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 22:12:52 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> opt;
        
        int cur = 0;
        for(int i = 0; i <= input.size(); i++){
            if(i == input.size())
                nums.push_back(cur);
            else{
                if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                    nums.push_back(cur);
                    cur = 0;
                    opt.push_back(input[i]);
                } else 
                    cur = cur * 10 + input[i] - '0';
            }
        }
        
        int n = nums.size();
        vector<vector<vector<int>>> f(nums.size(), vector<vector<int>>(nums.size(), vector<int>()));
        
        for(int len = 0; len < n; len++)
            for(int start = 0; start + len < n; start++)
                if(len == 0){
                    f[start][start + len] = vector<int>(1, nums[start]);
                }else {
                    for(int end = start + len - 1; end >= start; end--){
                        vector<int> temp = cal(f[start][end], f[end + 1][start + len], opt[end]);
                        f[start][start + len].insert(f[start][start + len].begin(), temp.begin(), temp.end());
                    }
                }
            
        return f[0][n - 1];
    }
    
private:
    vector<int> cal(vector<int> a, vector<int> b, char opt){
        vector<int> result;
        for(auto i:a)
            for(auto j:b)
                if(opt == '+')
                    result.push_back(i + j);
                else if(opt == '-')
                    result.push_back(i - j);
                else 
                    result.push_back(i * j);
        return result;
    }
};
