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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        
        queue<pair<TreeNode*, int>> q;
        map<int, vector<int>> vertical;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            TreeNode *curNode = q.front().first;
            int curPos = q.front().second;
            
            q.pop();
            vertical[curPos].push_back(curNode->val);
            
            if(curNode->left != nullptr)
                q.push(make_pair(curNode->left, curPos - 1));
            if(curNode->right != nullptr)
                q.push(make_pair(curNode->right, curPos + 1));
        }
        
        for(auto ver : vertical)
            result.push_back(ver.second);
            
        return result;
    }
};

