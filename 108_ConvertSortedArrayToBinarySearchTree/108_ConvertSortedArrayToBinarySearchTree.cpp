/*************************************************************************
	> File Name: 108_ConvertSortedArrayToBinarySearchTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 20 09:53:11 2016
 ************************************************************************/

#include<iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        
        if(nums.size() == 1)
            return new TreeNode(nums[0]);
            
        int mid = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        
        vector<int> leftVec, rightVec;
        leftVec.assign(nums.begin(), nums.begin() + mid);
        rightVec.assign(nums.begin() + mid + 1, nums.end());
        
        root->left = sortedArrayToBST(leftVec);
        root->right = sortedArrayToBST(rightVec);
        
        return root;
    }
};

int main() {
    return 0;
}
