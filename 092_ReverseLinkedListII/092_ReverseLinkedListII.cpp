/*************************************************************************
	> File Name: 092_ReverseLinkedListII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Sep 25 20:42:06 2016
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        return reverse(head, 1, m , n);  
    }
private:
    ListNode* reverse(ListNode* head, int count, int m, int n){
        if(count < m){
            head->next = reverse(head->next, count + 1, m ,n);
            return head;
        } else if(count == n){
            return head;
        } else {
            ListNode* newHead = reverse(head->next, count + 1, m, n);
            int nowCount = count + 1; 
            ListNode* now = newHead;
            while(nowCount != n){
                now = now->next;
                nowCount++;
            }
            head->next = now->next;
            now->next = head;
            
            return newHead;
        }
    }
};
