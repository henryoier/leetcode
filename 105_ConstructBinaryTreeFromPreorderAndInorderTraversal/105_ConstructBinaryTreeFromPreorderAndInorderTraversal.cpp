/*************************************************************************
	> File Name: 105_ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 21 20:52:09 2016
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
            return nullptr;
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

private:
    TreeNode* build(vector<int>& preorder, int pbegin, int pend, vector<int>& inorder, int ibegin, int iend){
        if(pend - pbegin == 0)
            return nullptr;
            
        int index;
        for(index = ibegin; index < iend; index++)
            if(inorder[index] == preorder[pbegin])
                break;
        
        int leftLen = index - ibegin, rightLen = iend - index - 1;
  
        TreeNode* root = new TreeNode(preorder[pbegin]);
        
        root->left = build(preorder, pbegin + 1, pbegin + leftLen + 1, inorder, ibegin, ibegin + leftLen);
        root->right = build(preorder, pbegin + leftLen + 1, pend, inorder, ibegin + leftLen + 1, iend);
        
        return root;
    }
};

int main() {
    return 0;
}
