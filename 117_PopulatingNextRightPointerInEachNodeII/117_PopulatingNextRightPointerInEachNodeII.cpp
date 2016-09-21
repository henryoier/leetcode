/*************************************************************************
	> File Name: 117_PopulatingNextRightPointerInEachNodeII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 20 23:10:19 2016
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
        if(root == nullptr)
            return;
            
        queue<TreeLinkNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeLinkNode *now = q.front();
            q.pop();
            
            if(now->left == nullptr && now->right == nullptr)
                continue;
            if(now->left != nullptr && now->right == nullptr){
                TreeLinkNode *p = getNext(now->next);
                if(p == nullptr){
                    q.push(now->left);
                    continue;
                }
                if(p->left != nullptr){
                    now->left->next = p->left;
                    q.push(now->left);
                    continue;
                } 
                if(p->right != nullptr){
                    now->left->next = p->right;
                    q.push(now->left);
                    continue;
                }
            }
            if(now->left == nullptr && now->right != nullptr){
                TreeLinkNode *p = getNext(now->next);
                if(p == nullptr){
                    q.push(now->right);
                    continue;
                }
                if(p->left != nullptr){
                    now->right->next = p->left;
                    q.push(now->right);
                    continue;
                } 
                if(p->right != nullptr){
                    now->right->next = p->right;
                    q.push(now->right);
                    continue;
                }
            }
            
            if(now->left != nullptr && now->right != nullptr){
                now->left->next = now->right;
                TreeLinkNode *p = getNext(now->next);
                if(p == nullptr){
                    q.push(now->left);
                    q.push(now->right);
                    continue;
                }
                if(p->left != nullptr){
                    now->right->next = p->left;
                    q.push(now->left);
                    q.push(now->right);
                    continue;
                } 
                if(p->right != nullptr){
                    now->right->next = p->right;
                    q.push(now->left);
                    q.push(now->right);
                    continue;
                }
            }
        }
    }
private:
    TreeLinkNode* getNext(TreeLinkNode *root){
        if(root == nullptr)
            return root;
        if(root->left == nullptr && root->right == nullptr)
            return getNext(root->next);
        else
            return root;
    }
};

int main() {
    return 0;
}
