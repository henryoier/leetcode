/*************************************************************************
	> File Name: 156_BinaryTreeUpsideDown.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct  5 00:48:04 2016
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == nullptr || root->left == nullptr)
            return root;
            
        TreeNode* newNode = upsideDownBinaryTree(root->left);
        TreeNode* now = newNode;
        while(now->right != nullptr)
            now = now->right;
        now->left = root->right;
        root->left = nullptr;
        root->right = nullptr;
        now->right = root;
        
        return newNode;
    }
};
