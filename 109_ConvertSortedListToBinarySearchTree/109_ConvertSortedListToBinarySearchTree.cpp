/*************************************************************************
	> File Name: 109_ConvertSortedListToBinarySearchTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 20 10:16:24 2016
 ************************************************************************/

#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        if(head->next == nullptr)
            return new TreeNode(head->val);
        
        int count = 0;
        ListNode *p = head;
        while(p != nullptr){
            count++;
            p = p->next;
        }
        
        count = count / 2;
        ListNode *pre, *now = head;
        for(int i = 0; i < count; i++){
            pre = now;
            now = now->next;
        }
        TreeNode *root = new TreeNode(now->val);
        pre->next = nullptr;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(now->next);
        
        return root;
    }
};

int main() {
    return 0;
}
