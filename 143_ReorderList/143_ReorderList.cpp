/*************************************************************************
	> File Name: 143_ReorderList.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 22 21:06:51 2016
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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;
            
        vector<ListNode*> list;
        ListNode *now = head;
        while(now != nullptr){
            list.push_back(now);
            now = now->next;
        }
        
        int i = 0, j = list.size() - 1;
        while(true){
            list[i]->next = list[j];
            i++;
            if(i == j){
                list[j]->next = nullptr;
                break;
            }
            list[j]->next = list[i];
            j--;
            if(i == j){
                list[i]->next = nullptr;
                break;
            }
        }
    }
};

