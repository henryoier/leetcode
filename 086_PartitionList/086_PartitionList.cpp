/*************************************************************************
	> File Name: 086_PartitionList.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Sep 24 23:44:59 2016
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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr)
            return head;
        if(head->val < x){
            head->next = partition(head->next, x);
            return head;
        } else{
            ListNode* newHead = partition(head->next, x);
            ListNode* now = newHead;
            if(now->val >= x){
                head->next = newHead;
                return head;
            }
            
            while(now->next != nullptr && now->next->val < x)
                now = now->next;
            head->next = now->next;
            now->next = head;
            
            return newHead;
        }
    }
};
