/*************************************************************************
	> File Name: 233_RectangleArea.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct 12 15:44:05 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return ((long)D - B) * ((long)C - A) + ((long)H - F) * ((long)G - E) - max(((long)min(C,G) - max(A, E)), (long)0)*max(((long)min(D, H) - max(B, F)), (long)0);
    }
};
