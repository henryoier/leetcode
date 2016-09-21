/*************************************************************************
	> File Name: 116_PopulatingNextRightPointersInEachNode.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 20 22:20:33 2016
 ************************************************************************/

#include<iostream>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr))
            return;
        if(root->left != nullptr && root->right == nullptr){
            connect(root->left);
            return;
        }
        if(root->left == nullptr && root->right != nullptr){
            connect(root->right);
            return;
        }
            
        root->left->next = root->right;
        if(root->next != nullptr)
            root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
    }
};

int main() {
    return 0;
}
