/*************************************************************************
	> File Name: 024_SwapNodesInPairs.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Aug 11 17:00:12 2016
 ************************************************************************/

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *one, *last, *newHead;
        bool first = true;
        newHead = head;

        while(head != NULL && head->next != NULL){
            one = head->next;
            head->next = one->next;
            one->next = head;
            head = head->next;
            if(first){
                newHead = one;
                first = false;
                last = one->next;
            } else {
                last->next = one;
                last = one->next;
            }
        }
        return newHead;
    }
};

int main(){
    ListNode *head;
    ListNode *last;
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
    ListNode *newHead = newSolution.swapPairs(head);
    //ListNode *newHead = head;
    while(newHead != NULL){
        cout << newHead->val << ' ';
        newHead = newHead->next;
    }
    return 0;
}
