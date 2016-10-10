/*************************************************************************
	> File Name: 366_FindLeavesOfBinaryTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  9 23:23:35 2016
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        int n = findDepth(root);
        return result;
    }
private:
    int findDepth(TreeNode* root){
        if(root == nullptr)
            return -1;
        if(root->left == nullptr && root->right == nullptr){
            if(result.empty())
                result.push_back(vector<int>(1, root->val));
            else
                result[0].push_back(root->val);
            return 0;
        }
        
        int cur = max(findDepth(root->left), findDepth(root->right)) + 1;
        if(result.size() <= cur)
            result.push_back(vector<int>(1, root->val));
        else
            result[cur].push_back(root->val);
        return cur;
    }
    vector<vector<int>> result;
};
