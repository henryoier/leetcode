/*************************************************************************
	> File Name: 237_DeleteNodeInALinkedList.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 19:49:01 2016
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
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* now = node;
        while(now->next != nullptr){
            if(now->next->next == nullptr){
                now->val = now->next->val;
                now->next = nullptr;
            } else{
                now->val = now->next->val;
                now = now->next;
            }
        }
    }
};
