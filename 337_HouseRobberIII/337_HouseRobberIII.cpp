/*************************************************************************
	> File Name: 337_HouseRobberIII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct 15 13:40:41 2016
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
    int rob(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if(f.count(root))
            return f[root];
            
        int include = 0, non_include = 0;
        if(root->left != nullptr)
            include += rob(root->left->left) + rob(root->left->right);
        if(root->right != nullptr)
            include += rob(root->right->left) + rob(root->right->right);
        include += root->val;
        non_include = rob(root->left) + rob(root->right);
        
        f[root] = max(include, non_include);
        return f[root];
    }
private:
    unordered_map<TreeNode*, int> f;
};
