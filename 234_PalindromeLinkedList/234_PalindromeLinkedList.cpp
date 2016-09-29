/*************************************************************************
	> File Name: 234_PalindromeLinkedList.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 29 00:36:11 2016
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
    bool isPalindrome(ListNode* head) {
        vector<int> a, b;
        
        ListNode *now = head;
        while(now!=nullptr){
            a.push_back(now->val);
            now = now->next;
        }
        
        b = a;
        reverse(b.begin(), b.end());
        
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
};
