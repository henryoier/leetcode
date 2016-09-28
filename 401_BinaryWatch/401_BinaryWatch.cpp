/*************************************************************************
	> File Name: 401_BinaryWatch.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 28 19:35:10 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        int b[10];
        vector<string> result;
        dfs(num, 0, b, result);
        
        return result;
    }
private:
    void dfs(int num, int depth, int* b, vector<string>& result){
        if(depth == 10)
            if(num == 0){
                string tempResult;
                int hour = b[0] * 8 + b[1] * 4 + b[2] * 2 + b[3] * 1;
                if(hour > 11)
                    return;
                tempResult = tempResult + to_string(hour);
                
                int second = b[4] * 32 + b[5] * 16 + b[6] * 8 + b[7] * 4 + b[8] * 2 + b[9] * 1;
                if(second > 59)
                    return;
                if(second > 9)
                    tempResult = tempResult + ':' + to_string(second);
                else
                    tempResult = tempResult + ":0" + to_string(second);
                    
                result.push_back(tempResult);
                return;
            }else return;
        
        b[depth] = 0;
        dfs(num, depth + 1, b, result);
        if(num > 0){
            b[depth] = 1;
            dfs(num - 1, depth + 1, b, result);
        }
    }
};
