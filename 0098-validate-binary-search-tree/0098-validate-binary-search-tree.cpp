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
    bool check(TreeNode* root){
        queue<TreeNode*>q;
        if(root->left) q.push(root->left);
        while(!q.empty()){
            TreeNode* x = q.front();
            if(x->val >= root->val) return false;
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
            q.pop();
        }
        if(root->right) q.push(root->right);
        while(!q.empty()){
            TreeNode* x = q.front();
            if(x->val <= root->val) return false;
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
            q.pop();
        }  
        return true;
        
    }
    bool isValidBST(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* x = q.front();
            if(!check(x)){return false;}
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
            q.pop();
        }  
        return true;
    }
};