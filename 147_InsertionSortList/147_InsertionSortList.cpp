/*************************************************************************
	> File Name: 147_InsertionSortList.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct  6 16:59:12 2016
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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *newHead = insertionSortList(head->next);

        if(head->val < newHead->val){
            head->next = newHead;
            return head;
        }
        
        ListNode *now = newHead;
        while(now->next != nullptr && head->val > now->next->val){
            now = now->next;
        }
        head->next = now->next;
        now->next = head;
        return newHead;
    }
};
