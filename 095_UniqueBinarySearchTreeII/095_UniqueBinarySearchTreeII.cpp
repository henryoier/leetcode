/*************************************************************************
	> File Name: 095_UniqueBinarySearchTreeII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Sep 19 16:56:18 2016
 ************************************************************************/

#include<iostream>

using namespace std;

/**
 *   Definition for a binary tree node.
 *    struct TreeNode {
 *       int val;
 *       TreeNode *left;
 *       TreeNode *right;
 *       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *       };
 *   
 **/

 class Solution {
     public:
     vector<TreeNode*> generateTrees(int n) {
                 if (n == 0)
                     return vector<TreeNode*>();
                 else
                     return genTree(1,n);   
             
     }
     private:
     vector<TreeNode*> genTree(int begin, int end) {
                 vector<TreeNode*> result;
                 
         if(begin > end){
                         result.push_back(nullptr);
                         return result;
                     
         }
         if(begin == end){
                         TreeNode *newRoot = new TreeNode(begin);
                         result.push_back(newRoot);
                         return result;
                     
         }
                 
         for(int root = begin; root <= end; root++){
                         vector<TreeNode*> left_nodes = genTree(begin, root - 1);
                         vector<TreeNode*> right_nodes = genTree(root + 1, end);
                         for(auto i = left_nodes.begin(); i != left_nodes.end(); ++i)
             for(auto j = right_nodes.begin(); j != right_nodes.end(); ++j){
                                     TreeNode *newRoot = new TreeNode(root);
                                     newRoot->left = *i;
                                     newRoot->right = *j;
                                     result.push_back(newRoot);
                                 
             }
                     
         }
                 return result;
             
     }

 };
