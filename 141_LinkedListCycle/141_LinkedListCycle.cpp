/*************************************************************************
	> File Name: 141_LinkedListCycle.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 22 20:23:56 2016
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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> hash;
        while(head != nullptr){
            if(hash.find(head) != hash.end())
                return true;
            else{
                hash.insert(head);
                head = head->next;
            }
        }
        return false;
    }
};

O(1) extra space;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        while(head != nullptr && fast != nullptr){
            head=head->next;
            if(fast->next == nullptr)
                break;
            else
                fast = fast->next->next;
            if(fast == head)
                return true;
        }
        return false;
    }
};


