/*************************************************************************
	> File Name: 099_RecoverBinarySearchTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Sep 25 22:08:28 2016
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
    void recoverTree(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            return;
        
        if(root->left == nullptr){
            TreeNode* rightMin = getMin(root->right);
            if(rightMin->val > root->val)
                recoverTree(root->right);
            else
                swap(root, rightMin);
            return;
        }
        
        if(root->right == nullptr){
            TreeNode* leftMax = getMax(root->left);
            if(leftMax->val < root->val)
                recoverTree(root->left);
            else
                swap(root, leftMax);
            return;
        } 
        
        TreeNode* leftMax = getMax(root->left);
        TreeNode* rightMin = getMin(root->right);
        if(root->val > leftMax->val && root->val < rightMin->val){
            recoverTree(root->left);
            recoverTree(root->right);
        } else if (root->val < leftMax->val && root->val > rightMin->val){
            swap(leftMax, rightMin);
        } else if(root->val < leftMax->val){
            swap(root, leftMax);
        } else {
            swap(root, rightMin);
        }
                    
    }
private:
    TreeNode* getMin(TreeNode* root){
        TreeNode* temp;
        TreeNode* minNode = root;
        
        if(root->left != nullptr){
            temp = getMin(root->left);
            if(temp->val < minNode->val)
                minNode = temp;
        }
            
        if(root->right != nullptr){
            temp = getMin(root->right);
            if(temp->val < minNode->val)
                minNode = temp;
        }
            
        return minNode;
    }
    
    TreeNode* getMax(TreeNode* root){
        TreeNode* temp;
        TreeNode* maxNode = root;
        
        if(root->left != nullptr){
            temp = getMax(root->left);
            if(temp->val > maxNode->val)
                maxNode = temp;
        }
            
        if(root->right != nullptr){
            temp = getMax(root->right);
            if(temp->val > maxNode->val)
                maxNode = temp;
        }
            
        return maxNode;
    }   

    void swap(TreeNode* a, TreeNode* b){
        int c;
        c = a->val;
        a->val = b->val;
        b->val = c;
    }
};
