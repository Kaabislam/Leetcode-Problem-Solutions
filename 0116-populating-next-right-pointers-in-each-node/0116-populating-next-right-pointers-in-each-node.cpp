/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<Node*>v;
            while(!q.empty()){
                Node* x = q.front();
                // cout << x->val << " ";
                if(x->left) v.push_back(x->left);
                if(x->right) v.push_back(x->right);
                q.pop();
            }
            // cout << endl;
            for(int i = 0;i < v.size();i++){
                if(i < v.size()-1){
                    v[i]->next = v[i+1];
                }
                q.push(v[i]);
            }
        }
        return root;
    }
};