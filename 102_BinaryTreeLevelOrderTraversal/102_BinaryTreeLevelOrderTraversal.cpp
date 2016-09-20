/*************************************************************************
	> File Name: 102_BinaryTreeLevelOrderTraversal.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 19 22:43:32 2016
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(0, root, result);
        
        return result;
    }
private:
    void dfs(int depth, TreeNode *root, vector<vector<int>>& result){
        if(root == nullptr)
            return;
            
        if(result.size() == depth){
            vector<int> temp;
            temp.push_back(root->val);
            result.push_back(temp);
            dfs(depth + 1, root->left, result);
            dfs(depth + 1, root->right, result);
        } else {
            result[depth].push_back(root->val);
            dfs(depth + 1, root->left, result);
            dfs(depth + 1, root->right, result);
        }
    }
};

int main () {
    return 0;
}
