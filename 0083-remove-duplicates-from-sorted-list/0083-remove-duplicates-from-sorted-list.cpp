/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        ListNode* prev = head,*curr = head->next;
        map<int,bool>m;
        m[prev->val] = true;
        while(curr){
            if(m.count(curr->val)){
                
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                m[curr->val] = true;
                curr = curr->next;
                prev = prev->next;
            }
            // cout << curr->val << " ";
            // curr = curr->next;
        }
        
        return head;
    }
};