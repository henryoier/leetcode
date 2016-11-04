/*************************************************************************
	> File Name: 255_VerifyPreorderSequenceInBinarySearchTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Nov  3 21:27:18 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.empty())
            return true;
        stack<int> s;
        int minReq = INT_MIN;
        for(int i = 0; i < preorder.size(); i++){
            if(i == 0)
                s.push(preorder[i]);
            else 
                if(preorder[i] < s.top())
                    if(preorder[i] < minReq)
                        return false;
                    else
                        s.push(preorder[i]);
                else {
                    while(!s.empty() && s.top() < preorder[i]){
                        minReq = s.top();
                        s.pop();
                    }
                    s.push(preorder[i]);
                }
        }
        return true;
    }
};
