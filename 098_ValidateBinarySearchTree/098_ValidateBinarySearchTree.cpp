/*************************************************************************
	> File Name: 098_ValidateBinarySearchTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 19 21:41:44 2016
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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        bool leftResult, rightResult;
        
        if(root->left == nullptr)
            leftResult = true;
        else
            leftResult = getMax(root->left) < root->val;
        
        if(root->right == nullptr)
            rightResult = true;
        else
            rightResult = getMin(root->right) > root->val;
        
        
        return isValidBST(root->left) && isValidBST(root->right) && leftResult && rightResult;
    }
private:
    int getMin(TreeNode* root){
        if(root == nullptr)
            return INT_MAX;
            
        if(root->left == nullptr)
            return root->val;
        else
            return getMin(root->left);
    }

    int getMax(TreeNode* root){
        if(root == nullptr)
            return INT_MIN;
            
        if(root->right == nullptr)
            return root->val;
        else
            return getMax(root->right);
    }
};

int main() {
    return 0;
}
