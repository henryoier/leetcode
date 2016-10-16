/*************************************************************************
	> File Name: 145_BinaryTreePostorderTraversal.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 22 22:03:24 2016
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        unordered_map<TreeNode*, bool> canPop;
        
        if(root == nullptr)
            return result;
        
        s.push(root);
        canPop.insert({root, false});
        
        while(!s.empty()){
            TreeNode *now = s.top();
            if((now->left == nullptr && now->right == nullptr) || canPop[now]){
                s.pop();
                result.push_back(now->val);
            } else {
                if(now->right != nullptr){
                    s.push(now->right);
                    canPop.insert({now->right,false});
                }
                if(now->left != nullptr){
                    s.push(now->left);
                    canPop.insert({now->left,false});
                }
                canPop[now] = true;
            }
        }
        return result;
    }
};

