/*************************************************************************
	> File Name: 142_LinkedListCycleII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 22 20:33:42 2016
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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hash;
        while(head != nullptr){
            if(hash.find(head) != hash.end())
                return head;
            else{
                hash.insert(head);
                head = head->next;
            }
        }
        return NULL;
    }
};

class Solution {
public:
      ListNode *detectCycle(ListNode *head) {
          ListNode *slow = head, *fast = head;
          while (fast && fast->next) {
              slow = slow->next;
              fast = fast->next->next;
              if (slow == fast) {
                  ListNode *slow2 = head;
                  while (slow2 != slow) {
                      slow2 = slow2->next;
                      slow = slow->next;
}
                  return slow2;
              }
}
          return nullptr;
      }
}

