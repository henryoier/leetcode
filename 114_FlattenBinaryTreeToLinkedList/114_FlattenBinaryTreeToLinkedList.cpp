/*************************************************************************
	> File Name: 114_FlattenBinaryTreeToLinkedList.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 20 11:15:27 2016
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
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
            
        vector<int> result;
        dfs(root, result);
        
        root->val = result[0];
        root->left = nullptr;
        TreeNode *pre = root;
        for(int i = 1; i < result.size(); i++){
            TreeNode *now = new TreeNode(result[i]);
            pre->right = now;
            pre = now;
        }
    }
private:
    void dfs(TreeNode* root, vector<int>& result) {
        if(root == nullptr)
            return;
        result.push_back(root->val);
        dfs(root->left, result);
        dfs(root->right, result);
    }
};

int main() {
    return 0;
}
