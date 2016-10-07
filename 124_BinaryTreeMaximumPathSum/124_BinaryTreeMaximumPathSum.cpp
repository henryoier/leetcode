/*************************************************************************
	> File Name: 124_BinaryTreeMaximumPathSum.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct  6 23:09:23 2016
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
    int maxPathSum(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
            
        int a = dfs(root);
        
        return result;
    }
private:
    int dfs(TreeNode *root){
        if(root == nullptr) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(root->val + left + right > result)
            result = root->val + left + right;
            
        return max(max(left, right) + root->val, 0); 
    }
    int result = -INT_MIN;
};
