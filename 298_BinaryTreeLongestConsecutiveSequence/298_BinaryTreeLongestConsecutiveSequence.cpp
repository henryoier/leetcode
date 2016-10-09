/*************************************************************************
	> File Name: 298_BinaryTreeLongestConsecutiveSequence.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  9 15:46:06 2016
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
    int longestConsecutive(TreeNode* root) {
        int a = dfs(root);
        
        return maxLength;
    }
    
private:
    int maxLength = 0;
    
    int dfs(TreeNode* root){
        if(root == nullptr)
            return 0;
            
        if(root->left == nullptr && root->right == nullptr){
            maxLength = max(1, maxLength);
            return 1;
        }
            
        if(root->left == nullptr){
            int right = dfs(root->right);
            if(root->val + 1 == root->right->val){
                int cur = right + 1;
                maxLength = max(cur, maxLength);
                return cur;
            } else {
                return 1;
            }
        } else if(root-> right == nullptr){
            int left = dfs(root->left);
            if(root->val + 1 == root->left->val){
                int cur = left + 1;
                maxLength = max(cur, maxLength);
                return cur;
            } else {
                return 1;
            }
        } else {
                int left = dfs(root->left);
                int right = dfs(root->right);
                
                int cur = 1;
                if(root->val + 1 == root->left->val){
                    cur = left + 1;
                    maxLength = max(cur, maxLength);
                }
                if(root->val + 1 == root->right->val){
                    cur = max(cur, right + 1);
                    maxLength = max(cur, maxLength);
                }
                return cur;
        }
    }
};
