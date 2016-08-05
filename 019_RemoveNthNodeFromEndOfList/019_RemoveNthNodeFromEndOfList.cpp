/*************************************************************************
	> File Name: 019_RemoveNthNodeFromEndOfList.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Aug  5 22:55:22 2016
 ************************************************************************/

#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* last = head;
        ListNode* now = head;
        
        if(now == NULL)
            return now;

        while(now != NULL){
            ListNode *tempNode = now;
            int tempN = n;
            while(tempN > 0){
                tempNode = tempNode->next;
                tempN--;
            }
            if(tempNode == NULL){
                if(now == head)
                    head = head->next;
                else
                    last->next = now->next;
                break;
            } else {
                if(now == head)
                    now = now->next;
                else{
                    last = last->next;
                    now = now->next;
                }          
            }
        }
        return head;
    }
};

int main(){
    ListNode *head;
    ListNode *last;
    int n = 2;
    for(int i = 0;i<5;i++){
        ListNode *tempNode = new ListNode(i);
        if(i == 0){
            head = tempNode;
            last = head;
        } else {
            last->next = tempNode;
            last = tempNode;
        }
    }
    Solution newSolution;
    ListNode *newHead = newSolution.removeNthFromEnd(head, n);
    //ListNode *newHead = head;
    while(newHead != NULL){
        cout << newHead->val << ' ';
        newHead = newHead->next;
    }
    return 0;
}
