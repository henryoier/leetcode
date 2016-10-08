/*************************************************************************
	> File Name: 250_CountUnivalSubtrees.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct  7 21:23:10 2016
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
    int countUnivalSubtrees(TreeNode* root) {
        bool a = isUnivalSubtree(root);
        return total;   
    }
private:
    bool isUnivalSubtree(TreeNode* root){
        if(root == nullptr)
            return true;
        if(root->left == nullptr && root->right == nullptr){
            total++;
            return true;
        }
        bool left = true, right = true;
        if(root->left != nullptr)
            if(isUnivalSubtree(root->left) && root->left->val == root->val)
                left = true;
            else
                left = false;
        if(root->right != nullptr)
            if(isUnivalSubtree(root->right) && root->right->val == root->val)
                right = true;
            else
                right = false;
        
        if(left && right){
            total++;
            return true;
        } else 
            return false;
    }
    int total = 0;
};
