/*************************************************************************
	> File Name: 129_SumRootToLeafNumbers.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 21 13:45:33 2016
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
    int sumNumbers(TreeNode* root) {
        vector<string> numStr = getNum(root);
        
        int result = 0;
        for(int i = 0; i < numStr.size(); i++)
            result += atoi(numStr[i].c_str());
        return result;
    }
private:
    vector<string> getNum(TreeNode* root){
        if(root == nullptr)
            return vector<string>();
            
        vector<string> left = getNum(root->left);
        vector<string> right = getNum(root->right);
        
        vector<string> result;
        for(int i = 0; i < left.size(); i++)
            result.push_back((char)(root->val + '0') + left[i]);
            
        for(int i = 0; i < right.size(); i++)
            result.push_back((char)(root->val + '0') + right[i]);
            
        if(left.size() == 0 && right.size() == 0)
            result.push_back(string(1, root->val + '0'));
            
        return result;
    }
};

int main() {
    return 0;
}
