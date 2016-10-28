/*************************************************************************
	> File Name: 222_CountCompleteTreeNodes.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct 28 15:50:14 2016
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
    int countNodes(TreeNode* root) {
        int h = height(root);
        if(h == 0)
            return 0;
            
        if(height(root->right) == h - 1)
            return (1 << (h - 1)) + countNodes(root->right);
        else
            return (1 << (h - 2)) + countNodes(root->left);
    }
private:
    int height(TreeNode* root){
        int result = 0;
        while(root != nullptr){
            result++;
            root = root->left;
        }
        return result;
    }
};
