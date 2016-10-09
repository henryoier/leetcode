/*************************************************************************
	> File Name: 285_InorderSuccessorInBST.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  8 23:35:44 2016
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root->val < p->val)
            return inorderSuccessor(root->right, p);
        else if(root->val > p->val) {
            TreeNode *temp = inorderSuccessor(root->left, p);
            return temp == nullptr?root:temp;
        } else{
            if(root->right == nullptr)
                return nullptr;
            else{
                TreeNode* node = root->right;
                while(node->left != nullptr)
                    node = node->left;
                return node;
            }
        }
    }
};
