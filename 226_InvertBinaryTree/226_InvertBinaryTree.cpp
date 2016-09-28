/*************************************************************************
	> File Name: 226_InvertBinaryTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 28 13:35:25 2016
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return root;
            
        TreeNode* temp;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        return root;
    }
};
