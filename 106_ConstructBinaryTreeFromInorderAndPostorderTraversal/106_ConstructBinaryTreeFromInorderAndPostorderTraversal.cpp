/*************************************************************************
	> File Name: 106_ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 21 21:11:36 2016
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0)
            return nullptr;
            
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }

private:
    TreeNode* build(vector<int>& inorder, int ibegin, int iend, vector<int>& postorder, int pbegin, int pend){
        if(iend - ibegin == 0)
            return nullptr;
            
        int index;
        for(index = ibegin; index < iend; index++)
            if(inorder[index] == postorder[pend - 1])
                break;
        
        int leftLen = index - ibegin, rightLen = iend - index - 1;
  
        TreeNode* root = new TreeNode(postorder[pend - 1]);
        
        root->left = build(inorder, ibegin, ibegin + leftLen, postorder, pbegin, pbegin + leftLen);
        root->right = build(inorder, ibegin + leftLen + 1, iend, postorder, pbegin + leftLen, pbegin + leftLen + rightLen);
        
        return root;
    }
};

int main() {
    return 0;
}
