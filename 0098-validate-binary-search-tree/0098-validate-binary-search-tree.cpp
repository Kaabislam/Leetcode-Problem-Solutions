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
    bool isValidBST(TreeNode* root) {
        
        queue<pair<long long,long long>>q1;
        queue<TreeNode*>q2;
        q2.push(root);
        q1.push({LLONG_MIN,LLONG_MAX});
        while(!q2.empty()){
            pair<long long,long long>x = q1.front();
            TreeNode *y = q2.front();
            // cout << y->val << " " << x.first << " " << x.second << endl;
            if(y->val <= x.first or y->val >= x.second){
                
                // cout << y->val << endl;
                return false;
            }
            
            if(y->left){
                
                q2.push(y->left);
                q1.push({x.first,y->val});
            }
            if(y->right){
                q2.push(y->right);
                q1.push({y->val,x.second});
            }
            
            
            
            
            q1.pop();
            q2.pop();
        }
        return true;
    }
};