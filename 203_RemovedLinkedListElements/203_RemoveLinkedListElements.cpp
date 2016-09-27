/*************************************************************************
	> File Name: 203_RemoveLinkedListElements.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 27 00:16:35 2016
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return head;
        while(head != nullptr && head->val == val)
            head = head->next;
            
        ListNode *now = head;
        ListNode *pre;
        while(now != nullptr){
            if(now->val == val){
                pre->next = now->next;
                now = now->next;
            } else {
                pre = now;
                now = now->next;
            }
        }
        
        return head;
    }
};
