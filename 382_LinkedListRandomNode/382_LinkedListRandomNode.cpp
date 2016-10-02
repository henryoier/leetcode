/*************************************************************************
	> File Name: 382_LinkedListRandomNode.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  2 01:07:29 2016
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ListNode *now = head;
        this->head = head;
        
        while(now != nullptr){
            n++;
            now = now->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int index = rand() % n;
        
        ListNode *now = head; 
        while(index > 0){
            now = now->next;
            index--;
        }
        
        return now->val;
    }
private:
    ListNode *head;
    int n = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
