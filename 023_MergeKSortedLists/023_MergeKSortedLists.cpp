/*************************************************************************
	> File Name: 023_MergeKSortedLists.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Aug  8 17:39:04 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;


/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        for(int i = 0; i < lists.size(); i++){
            result = mergeTwoLists(result, lists[i]);
        }

        return result;
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head, *last;
        if(l1 == NULL && l2 == NULL)
            return NULL;
        
        if(l2 == NULL){
            head = l1;
            l1 = l1->next;
        }else if(l1 == NULL){
            head = l2;
            l2 = l2->next;
        } else if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        } else if(l1->val >= l2->val){
            head = l2;
            l2 = l2->next;
        }

        last = head;

        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                last->next = l1;
                last = l1;
                l1 = l1->next;
            } else {
                last->next = l2;
                last = l2;
                l2 = l2->next;
            }
        }

        while(l1 != NULL){
            last->next = l1;
            last = l1;
            l1 = l1->next;
        }

        while(l2 != NULL){
            last->next = l2;
            last = l2;
            l2 = l2->next;
        }

        return head;
    }
};

int main(){
    ListNode *head1, *head2;
    ListNode *last;
    
    for(int i = 0;i<11;i+=2){
        ListNode *tempNode = new ListNode(i);
        if(i == 0){
            head1 = tempNode;
            last = head1;
        } else {
            last->next = tempNode;
            last = tempNode;
        }
    }

    for(int i = 1;i<11;i+=2){
        ListNode *tempNode = new ListNode(i);
        if(i == 1){
            head2 = tempNode;
            last = head2;
        } else {
            last->next = tempNode;
            last = tempNode;
        }
    } 

    Solution newSolution;
    vector<ListNode*> lists;
    lists.push_back(head1);
    lists.push_back(head2);

    ListNode *newHead = newSolution.mergeKLists(lists);
    //ListNode *newHead = head2;
    while(newHead != NULL){
        cout << newHead->val << ' ';
        newHead = newHead->next;
    }
    return 0;
}


