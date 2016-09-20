/*************************************************************************
	> File Name: 110_BalancedBinaryTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 20 10:21:53 2016
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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        else
            return abs(getHeight(root->left) - getHeight(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int getHeight(TreeNode *root){
        if(root == nullptr)
            return 0;
        else
            return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};

int main() {
    return 0;
}
