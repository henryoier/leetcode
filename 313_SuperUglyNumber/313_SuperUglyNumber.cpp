/*************************************************************************
	> File Name: 313_SuperUglyNumber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct  4 20:47:03 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> idx(primes.size(), 0);
        vector<int> next(primes.size(), 0);
        vector<int> f(n , 0);
        
        f[0] = 1;
        for(int i = 0; i < primes.size(); i++)
            next[i] = primes[i];
        
        for(int i = 1; i < n; i++){
            f[i] = INT_MAX; 
            for(int j = 0; j < primes.size(); j++)
                f[i] = min(f[i], next[j]);
            for(int j = 0; j < primes.size(); j++)
                if(f[i] == next[j])
                    next[j] = f[++idx[j]] * primes[j];
        }
        return f[n - 1];
    }
};
