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
    vector<int>postorder;
    void t(TreeNode* root){
        if(root == NULL) return;
        if(root->left) t(root->left);
        if(root->right) t(root->right);
        postorder.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        t(root);
        return postorder;
    }
};