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
    vector<vector<int>> func(TreeNode* root){
        vector<vector<int>> ans;
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int>v;
            while(s != 0){
                v.push_back(q.front()->val);
                if(q.front()->left)q.push(q.front()->left);
                if(q.front()->right)q.push(q.front()->right);
                q.pop();
                s--;
            }
            ans.push_back(v);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        return func(root);
    }
};