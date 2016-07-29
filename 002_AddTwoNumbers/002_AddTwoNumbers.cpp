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
    ListNode() {};
    ListNode(ListNode *a) : val(a->val), next(a->next){}
    ListNode(int x) : val(x), next(NULL) {}
};

/*class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode
    }
};*/

int main(){
    int len1,len2,n;
    cin >> len1 >> len2;

    ListNode *last, *l1, *l2;

    for(int i = 0; i < len1; i++){
        cin >> n;
        ListNode *now(n);
        if( i == 0 ){
            l1 = now;
            last->next = now;
            last = now;
        }else{
            last->next = now;
            last = now;
        }
    }

     for(int i = 0; i < len2; i++){
        cin >> n;
        ListNode *now(n);
        if( i == 0 ){
            l2 = now;
            last->next = now;
            last = now;
        }else{
            last->next = now;
            last = now;
        }
    }

    ListNode *now = l1;
    while(now->next != NULL){
        cout << now->val;
        now = now->next;
    }
}
