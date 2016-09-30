/*************************************************************************
	> File Name: 257_BinaryTreePaths.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 22:28:59 2016
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr)
            return vector<string>();
        if(root->left == nullptr && root->right == nullptr)
            return vector<string>(1, to_string(root->val));
        
        vector<string> result;
        if(root->left != nullptr){
            vector<string> temp = binaryTreePaths(root->left);
            for(int i = 0; i < temp.size();i++)
                temp[i] = to_string(root->val) + "->" + temp[i];
            result.insert(result.end(), temp.begin(), temp.end());
        }
        if(root->right != nullptr){
            vector<string> temp = binaryTreePaths(root->right);
            for(int i = 0; i < temp.size();i++)
                temp[i] = to_string(root->val) + "->" + temp[i];
            result.insert(result.end(), temp.begin(), temp.end());
        }
        
        return result;
    }
};
