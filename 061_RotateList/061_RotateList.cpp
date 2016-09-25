/*************************************************************************
	> File Name: 061_RotateList.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Sep 24 21:05:13 2016
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0)
            return head;
            
        ListNode* now = head;
        int count = 1;
        while(now->next != nullptr){
            count++;
            now = now->next;
        }
        int index = k>count?count - k%count:count - k;
        ListNode* pre = now;
        now = head;
        
        for(int i = 0; i < index;i++){
            pre = now;
            if(now->next == nullptr)
                now = head;
            else
                now = now->next;
        }
        
        if(now == head) return head;
        
        ListNode *newHead = now;
        pre->next = nullptr;
        
        while(now->next != nullptr)
            now = now->next;
            
        now->next = head;
        return newHead;
    }
};
