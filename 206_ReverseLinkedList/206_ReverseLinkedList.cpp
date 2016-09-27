/*************************************************************************
	> File Name: 206_ReverseLinkedList.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 27 11:00:58 2016
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = reverseList(head->next);
        
        ListNode* now = newHead;
        while(now->next != nullptr) now = now->next;
        
        now->next = head;
        head->next = nullptr;
        
        return newHead;
    }
};
