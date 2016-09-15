/*************************************************************************
	> File Name: 082_RemoveDuplicatesFromSortedListII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 15 16:47:10 2016
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
        vector<bool> del;
        
        ListNode *now = head;
        int lastn = INT_MAX;
        
        while(now != NULL){
            if(now->val == lastn || (now->next != NULL && now->val == now->next->val)){
                del.push_back(true);
            } else
                del.push_back(false);
            lastn = now->val;
            now = now->next;
        }
        
        now = head;
        ListNode *last = NULL;
        
        int count = 0;
        while(now != NULL){
            if(del[count]) {
                if(last != NULL){
                    last->next = now->next;
                } else{
                    head = head->next;
                }
            } else {
                    last = now;
            }
            now = now->next;
            count++;
        }
        
        return head;
    }
};

