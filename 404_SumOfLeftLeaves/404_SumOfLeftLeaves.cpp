/*************************************************************************
	> File Name: 404_SumOfLeftLeaves.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 28 16:39:08 2016
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr))
            return 0;
        if(root->left != nullptr) 
            if(root->left->left == nullptr && root->left->right == nullptr)
                return sumOfLeftLeaves(root->right) + root->left->val;
            else
                return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        else
            return sumOfLeftLeaves(root->right);
    }
};
