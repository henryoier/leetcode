/*************************************************************************
	> File Name: 204_CountPrimes.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct  4 23:59:42 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n < 3)
            return 0;
        vector<bool> f(n + 1, true);
        
        int result = 0;
        f[2] = true;
        for(int i = 2; i < n; i++){
            if(f[i]){
                result++;
                int k = i * 2;
                while(k < n){
                    f[k] = false;
                    k += i;
                }
            }
        }
        return result;
    }
};
