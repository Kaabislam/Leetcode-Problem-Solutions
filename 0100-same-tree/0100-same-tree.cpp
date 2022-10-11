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
    vector<int> tree(TreeNode* p){
        vector<int>v1;
        queue<TreeNode*>v;
        if(p){
            v1.push_back(p->val);
            v.push(p);
        }
        
        while(!v.empty()){
            TreeNode* x = v.front();
            //cout << x->val << endl;
            v.pop();
            if(x->left){
                v.push(x->left);
                v1.push_back(x->left->val);
            }
            else v1.push_back(-1);
            if(x->right){
                v1.push_back(x->right->val);
                v.push(x->right);
            }
            else v1.push_back(-1);
        }
       
        return v1;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>v1 = tree(p),v2 = tree(q);
        if(v1==v2) return true;
        // for(int i = 0;i < v1.size();i++){
        //     cout << v1[i] << " ";
        // }
        return false;
    }
};