/*************************************************************************
	> File Name: 113_PathSumII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 20 10:49:31 2016
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, 0, sum, path, result);
        
        return result;
    }
private:
    void dfs(TreeNode *root, int depth, int sum, vector<int>& path, vector<vector<int>>& result){
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr)
            if(root->val == sum){
                path.push_back(root->val);
                result.push_back(path); 
                path.erase(path.begin() + depth);
                return;
            } else return;
            

        path.push_back(root->val);

        dfs(root->left, depth + 1, sum - root->val, path, result);
        dfs(root->right, depth + 1, sum - root->val, path, result);
        
        path.erase(path.begin() + depth);
    }
};

int main() {
    return 0;
}
