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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head,*fast = head->next;
        bool even = false;int c = 0;
        while(fast){
            slow = slow->next;
            c += 1;
            if(fast->next) fast = fast->next->next;
            else{
                even = true;
                break;
            }
        }
        if(!even) slow = slow->next;
        ListNode *prev = NULL,*curr = slow;
        while(curr){
            ListNode *x = curr->next;
            curr->next = prev;
            prev = curr;
            curr = x;
        }
        while(c){
            if(prev->val != head->val) return false;
            prev = prev->next;
            head = head->next;
            c--;
        }
        return true;
    }
};