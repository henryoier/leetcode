/*************************************************************************
	> File Name: 138_CopyListWithRandomPointer.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct 26 20:46:25 2016
 ************************************************************************/

#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr)
            return nullptr;
            
        RandomListNode *newhead = new RandomListNode(head->label);
        hash[head->label] = newhead;
        
        if(head->next != nullptr)
            if(hash.count(head->next->label))
                newhead->next = hash[head->next->label];
            else
                newhead->next = copyRandomList(head->next);
                
        if(head->random != nullptr)
            if(hash.count(head->random->label))
                newhead->random = hash[head->random->label];
            else
                newhead->random = copyRandomList(head->random);
                
        return newhead;
    }
private:
    unordered_map<int, RandomListNode*> hash;
    
};
