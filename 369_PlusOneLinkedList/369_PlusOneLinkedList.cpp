/*************************************************************************
	> File Name: 369_PlusOneLinkedList.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct 10 11:41:58 2016
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
    ListNode* plusOne(ListNode* head) {
        head = getPlusOne(head);
        if(head->val > 9){
            ListNode *newHead = new ListNode(1);
            head->val = 0;
            newHead->next = head;
            return newHead;
        } else
            return head;
    }
private:
    ListNode* getPlusOne(ListNode* head){
        if(head->next == nullptr){
            head->val += 1;
            return head;
        }
        head->next = getPlusOne(head->next);
        if(head->next->val > 9){
            head->val += 1;
            head->next->val = head->next->val % 10;
        }
        
        return head;
    }
};
