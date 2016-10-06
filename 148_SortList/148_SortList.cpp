/*************************************************************************
	> File Name: 148_SortList.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct  6 17:44:52 2016
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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *now = head;
        int n = 0;
        while(now != nullptr){
            n++;
            now = now->next;
        }
        return MergeSort(head, n);
    }
private:
    ListNode* MergeSort(ListNode* head, int n){
        if(n == 1)
            return head;
            
        ListNode *now = head;
        int i;
        for(i = 0; i < (n - 1) / 2; i++)
            now = now->next;
        
        ListNode *right = MergeSort(now->next, n - i  - 1);
        now->next = nullptr;
        ListNode *left = MergeSort(head, i + 1);
        
        ListNode *newHead;
        if(left->val < right->val){
            newHead = left;
            left = left->next;
        } else{
            newHead = right;
            right = right->next;
        }
        
        now = newHead;
        while(right != nullptr && left != nullptr){
            if(left->val < right->val){
                now->next = left;
                now = now->next;
                left = left->next;
            } else {
                now->next = right;
                now = now->next;
                right = right->next;
            }
        }
        while(right != nullptr){
            now->next = right;
            now = now->next;
            right = right->next;
        }
        while(left != nullptr){
            now->next = left;
            now = now->next;
            left = left->next;
        }
        now->next = nullptr;
        return newHead;
    }
};
