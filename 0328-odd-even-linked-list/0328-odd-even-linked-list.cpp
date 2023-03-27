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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        int c = 1;
        ListNode *thead = head,*h1 = NULL,*t1 = NULL,*h2 = NULL,*t2 = NULL;
        
        while(thead){
            ListNode *x = new ListNode(thead->val);
            if(c%2){
                if(c == 1){
                    t1 = x;
                    h1 = x;
                }
                else{
                    t1->next = x;
                    t1 = t1->next;
                    if(h1->next == NULL) h1->next = t1;
                }
            }
            else{
                if(c == 2){
                    t2 = x;
                    h2 = x;
                }
                else{
                    t2->next = x;
                    t2 = t2->next;
                    if(h2->next == NULL) h2->next = t2; 
                }
            }
            thead = thead->next;
            c += 1;
        }
        t1->next = h2;
        return h1;
        
    }
};