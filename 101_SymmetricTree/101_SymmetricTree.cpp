/*************************************************************************
	> File Name: 101_SymmetricTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 19 22:33:55 2016
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
            
        return isSame(root->left,root->right);   
    }
    
private:
    bool isSame(TreeNode* p, TreeNode *q){
        if(p == nullptr && q == nullptr)
            return true;
        if((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
            return false;
        
        return isSame(p->left, q->right) && isSame(p->right, q->left) && p->val == q->val;
    }
};

int main() {
    return 0;
}
