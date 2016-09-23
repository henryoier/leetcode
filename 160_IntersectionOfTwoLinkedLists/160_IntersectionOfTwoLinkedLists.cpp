/*************************************************************************
	> File Name: 160_IntersectionOfTwoLinkedLists.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 23 13:36:26 2016
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
            
        ListNode *pa, *pb, *hb, *ha;
        for(pa = headA, pb = headB; pa!=nullptr && pb!= nullptr; pa = pa->next, pb = pb->next);
        if(pa != nullptr){
            for(ha = headA; pa != nullptr; pa = pa->next, ha = ha->next);
            hb = headB;
        } else if(pb != nullptr){
            for(hb = headB; pb != nullptr; pb = pb->next, hb = hb->next);
            ha = headA;
        } else {
            ha = headA; 
            hb = headB;
        }
        for(;ha != nullptr && hb != nullptr; ha = ha->next, hb = hb->next)
            if(ha == hb)
                return ha;
        return nullptr;
    }
};


