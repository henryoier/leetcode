/*************************************************************************
	> File Name: 270_ClosestBinarySearchTreeValue.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  8 20:45:05 2016
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
    int closestValue(TreeNode* root, double target) {
        if(root->val == target)
            return root->val;
            
        if(target > root->val)
            if(root->right == nullptr)
                return root->val;
            else {
                int rightNum = closestValue(root->right, target);
                if(abs(root->val - target) < abs(rightNum - target))
                    return root->val;
                else
                    return rightNum;
            }
        else
            if(root->left == nullptr)
                return root->val;
            else {
                int leftNum = closestValue(root->left, target);
                if(abs(root->val - target) < abs(leftNum - target))
                    return root->val;
                else
                    return leftNum;
            }
    }
};
