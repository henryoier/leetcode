/*************************************************************************
	> File Name: 100_SameTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 19 22:23:57 2016
 ************************************************************************/

#include<iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        if((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
            return false;
            
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val;
    }
};

int main() {
    return 0;
}
