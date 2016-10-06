/*************************************************************************
	> File Name: 338_CountingBits.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct  5 20:49:57 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> f(num + 1, 0);
        if(num == 0)
            return f;
            
        int last = 1;
        f[1] = 1;
        for(int i = 2; i <= num; i++){
            if(i == 2 * last){
                f[i] = 1;
                last = i;
            } else {
                f[i] = f[i - last] + 1;
            }
        }
        return f;
    }
};
