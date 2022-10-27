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
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        long long int ans = 1;
        map<TreeNode*,long long int>m;
        m[root] = 0;
        
        while(!q.empty()){
            vector<TreeNode*>v;
            vector<long long int>v2;
            TreeNode* start = q.front();
            //cout << start->val << " -- ";
            while(!q.empty()){
                TreeNode* x = q.front();
                q.pop();
                if(x->left){
                    //cout << x->left->val << " " << m[x] << endl;
                    v.push_back(x->left);
                    m[x->left] = (m[x]-m[start])*2 + 1;
                    v2.push_back(m[x->left]);
                }
                if(x->right){
                    v.push_back(x->right);
                    m[x->right] = (m[x]-m[start])*2 + 2;
                    v2.push_back(m[x->right]);
                }
                
               // cout << x->val << " " ;
            }
            //cout << endl;
            sort(v2.begin(),v2.end());
            if(v2.size()) ans = max(ans,v2[v2.size()-1]- v2[0]+1);
            for(int i = 0;i < v.size();i++){
                q.push(v[i]);
            }
            
        }
        return ans;
        
    }
};