/*************************************************************************
	> File Name: 328_OddEvenLinkedList.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct  4 00:05:03 2016
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        else 
            return getList(head, 1).first;
    }
private:
    pair<ListNode*, int> getList(ListNode* head, int order){
        if(head->next == nullptr)
            if(order % 2 != 0)
                return pair<ListNode* ,int>(head, 1);
            else
                return pair<ListNode*, int>(head, 0);
                
        if(order % 2 == 0){
            pair<ListNode*, int> newPair = getList(head->next, order + 1);
            ListNode *now = newPair.first;
            for(int i = 1; i < newPair.second; i++)
                now = now -> next;
            head->next = now->next;
            now->next = head;
            
            return pair<ListNode*, int>(newPair.first, newPair.second);
        } else {
            pair<ListNode*, int> newPair = getList(head->next, order + 1);
            head->next = newPair.first;
            return pair<ListNode*, int>(head, newPair.second + 1);
        }
    }
};
