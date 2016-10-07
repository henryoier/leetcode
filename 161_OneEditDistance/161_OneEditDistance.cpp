/*************************************************************************
	> File Name: 161_OneEditDistance.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct  6 21:50:08 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        bool change = false;
        for(int i = 0; i < min(s.length(), t.length()); i++)
            if(s[i] != t[i] && !change){
                string a, b;
                a = s; b = t;
                a[i] = b[i];
                if(a == b)
                    return true;
            
                a[i] = s[i]; b[i] = s[i];
                if(a == b)
                    return true;
                b = t;
                a.insert(i, 1, b[i]);
                if(a == b)
                    return true;
                a = s; b = t;
                b.insert(i, 1, a[i]);
                if(a == b)
                    return true;
                return false;
            } 
                
        if(s.length() - t.length() == 1 || t.length() - s.length() == 1)
            return true;
        else
            return false;
    }
};
