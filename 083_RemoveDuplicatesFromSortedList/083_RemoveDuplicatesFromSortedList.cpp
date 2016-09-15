/*************************************************************************
	> File Name: 083_RemoveDuplicatesFromSortedList.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 15 16:53:10 2016
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *last = NULL, *now = head;
        while(now != NULL){
            if(last != NULL && now->val == last->val){
                last->next = now->next;
            } else{
                last = now;
            }
                now = now->next;
        }
        return head;
    }
};

