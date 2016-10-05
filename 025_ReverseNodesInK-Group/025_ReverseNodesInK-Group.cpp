/*************************************************************************
	> File Name: 025_ReverseNodesInK-Group.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct  5 10:18:02 2016
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *now = head;
        int n = 0;
        while(now != nullptr){
            n++;
            now = now->next;
        }
        return reverse(head, k, 1, n);
    }
private:
    ListNode* reverse(ListNode* head, int k, int order, int n){
        if(head == nullptr || head->next == nullptr)
            return head;

        cout << head->val << order << n << endl;
        ListNode *newNode;
        newNode = reverse(head->next, k, order + 1, n);
            
        if(order % k == 0 || order > n/k * k){
            head->next = newNode;
            return head;
        } else {
            ListNode* now = newNode;
            int t = order;
            while((t + 1) % k != 0){
                now = now->next;
                t++;
            }
            head->next = now->next;
            now->next = head;
            return newNode;
        }
    }
};
