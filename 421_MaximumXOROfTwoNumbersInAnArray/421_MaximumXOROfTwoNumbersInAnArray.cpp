/*************************************************************************
	> File Name: 421_MaximumXOROfTwoNumbersInAnArray.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct 26 21:33:22 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root = new TrieNode();
        
        for(auto i:nums){
            insertNode(root, i);   
        }    
        
        int maxRes = 0;
        for(auto n:nums){
            TrieNode *p = root;
            int cur = 0;
            for(int i = 31; i >= 0; i--){
                int d = ((1 << i) & n) > 0;
                if(p->node[1 - d]){
                    p = p->node[1 - d];
                    cur += (1 << i);
                } else {
                    p = p->node[d];
                }
            }
            maxRes = max(maxRes, cur);
        }
        
        return maxRes;
    }
private:
    struct TrieNode{
        TrieNode* node[2];
        TrieNode(){
            node[0] = NULL;
            node[1] = NULL;
        }
    };
    
    void insertNode(TrieNode* root, int n){
        for(int i = 31; i >= 0; i--){
            int d = ((1 << i) & n) > 0;
            if(root->node[d] != NULL){
                root = root->node[d];
            } else {
                root->node[d] = new TrieNode();
                root = root->node[d];
            }
        }
    }
};
