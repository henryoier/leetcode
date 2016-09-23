/*************************************************************************
	> File Name: 144_BinaryTreePreorderTraversal.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 22 21:37:36 2016
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr)
            return result;
            
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* now = s.top();
            s.pop();
            result.push_back(now->val);
            if(now->right != nullptr)
                s.push(now->right);
            if(now->left != nullptr)
                s.push(now->left);
        }
        
        return result;
    }
};

