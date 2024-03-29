/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>preorder;
    void traverse(TreeNode* root){
        if(root == NULL) return;
        preorder.push_back(root->val);
        if(root->left) traverse(root->left);
        if(root->right) traverse(root->right);
        
        

    }
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return preorder;
    }
};