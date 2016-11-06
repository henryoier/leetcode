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
    int pathSum(TreeNode* root, int sum) {
        target = sum;
        getSum(root);
        
        return count;
    }
private:
    int target;
    int count = 0;
    
    vector<int> getSum(TreeNode* root){
        if(root == nullptr)
            return vector<int>();
            
        vector<int> result(1, 0);
        vector<int> temp = getSum(root->left);
        
        result.insert(result.end(), temp.begin(), temp.end());
        temp = getSum(root->right);
        result.insert(result.end(), temp.begin(), temp.end());
        
        for(int i = 0; i < result.size(); i++){
            result[i] += root->val;
            if(result[i] == target)
                count++;
        }
        return result;
    }
};
