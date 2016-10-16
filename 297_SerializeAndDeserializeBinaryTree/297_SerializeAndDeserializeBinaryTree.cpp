/*************************************************************************
	> File Name: 297_SerializeAndDeserializeBinaryTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct 15 21:47:40 2016
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "null,";
        return to_string(root->val) + ',' + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        return de(data);
    }
private:
    TreeNode* de(string& data){
        int idx = data.find(',');
        string cur = data.substr(0, idx);
        data = data.substr(idx + 1);
        
        if(cur == "null")
            return nullptr;
        else{
            TreeNode* root = new TreeNode(stoi(cur));
            
            root->left = de(data);
            root->right = de(data);
            
            return root;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
