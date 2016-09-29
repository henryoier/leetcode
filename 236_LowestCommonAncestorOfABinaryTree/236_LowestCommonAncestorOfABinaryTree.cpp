/*************************************************************************
	> File Name: 236_LowestCommonAncestorOfABinaryTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 19:36:28 2016
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)
            return root;
            
        bool pInLeft = findNode(root->left, p), qInLeft = findNode(root->left, q);
        if(pInLeft && qInLeft)
            return lowestCommonAncestor(root->left, p, q);
            
        if(!pInLeft && !qInLeft)
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
private:
    bool findNode(TreeNode* root, TreeNode* target){
        if(root == nullptr)
            return false;
        if(root == target)
            return true;
        
        return findNode(root->left, target) || findNode(root->right, target);
    }
};

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr ||root == p || root == q)
            return root;
        TreeNode *inLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode *inRight = lowestCommonAncestor(root->right, p, q);
        
        if(inLeft == nullptr)
            return inRight;
        else if(inRight == nullptr)
            return inLeft;
        else 
            return root;
    }
};
