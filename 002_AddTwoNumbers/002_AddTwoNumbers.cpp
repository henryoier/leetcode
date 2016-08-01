/*************************************************************************
	> File Name: 002_AddTwoNumbers.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Jul 25 15:40:32 2016
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result, *now, *last;
        int carry = 0;
        bool head = true; 
        while(l1 != NULL && l2 != NULL){
            now = new ListNode(0); // The only initialization function
            now->val = l1->val + l2->val + carry;
            carry = now->val / 10;
            now->val = now->val % 10;
            
            if(head){
                result = now;
                last = now;
                head = false;
            } else{
                last->next = now;
                last = now;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            now = new ListNode(0);
            now->val = l1->val + carry;
            carry = now->val / 10;
            now->val = now->val % 10;

            last->next = now;
            last = now;

            l1 = l1->next;
        }

        while(l2 != NULL){
            now = new ListNode(0);
            now->val = l2->val + carry;
            carry = now->val / 10;
            now->val = now->val % 10;

            last->next = now;
            last = now;

            l2 = l2->next;
        }

        if(carry != 0){
            now = new ListNode(carry);
            last->next = now;
        }

        return result;
    }
};

int main(){
    int len1,len2,n;
    cin >> len1 >> len2;

    ListNode *last, *l1, *l2;

    for(int i = 0; i < len1; i++){
        cin >> n;
        ListNode* now;
        now = new ListNode(n);
        if( i == 0 ){
            l1 = now;
            last = now;
        }else{
            last->next = now;
            last = now;
        }
    }

    for(int i = 0; i < len2; i++){
        cin >> n;
        ListNode* now;
        now = new ListNode(n);
        if( i == 0 ){
            l2 = now;
            last = now;
        }else{
            last->next = now;
            last = now;
        }
    }

    Solution newSolution;
    ListNode *result = newSolution.addTwoNumbers(l1, l2);

    while(result != NULL){
        cout << result->val;
        result = result->next;
    }

    return 0;
}
