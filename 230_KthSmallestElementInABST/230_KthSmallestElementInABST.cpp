/*************************************************************************
	> File Name: 230_KthSmallestElementInABST.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 28 23:57:46 2016
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        s.push(root);
        while(s.top()->left != nullptr)
            s.push(s.top()->left);
            
        while(!s.empty()){
            if(s.top() -> right != nullptr){
                TreeNode *rightTree = s.top()->right;
                k--;
                if(k == 0)
                    return s.top()->val;
                s.pop();
                s.push(rightTree);
                while(s.top()->left!=nullptr)
                    s.push(s.top()->left);
            } else {
                k--;
                if(k == 0)
                    return s.top()->val;
                s.pop();
            }
        }
        return 0;
    }

};
