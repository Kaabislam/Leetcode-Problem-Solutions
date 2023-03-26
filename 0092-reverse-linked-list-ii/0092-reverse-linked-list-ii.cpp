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
    ListNode* findlast(ListNode* head){
        while(head){
            if(head->next == NULL) return head;
            head = head->next;
        }
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int c = 1;
        ListNode *sh = head,*st = head,*t = head,*w = NULL,*z = NULL;
        while(t){
            if(c == left) sh = t;
            if(c == right) st = t;
            if(c == left-1) w = t;
            if(c == right+1) z = t;
            t = t->next;
            c+=1;
        }
        st = st->next;
        ListNode *prev = NULL,*curr = sh;
        while(curr!=st){
            ListNode* x = curr->next;
            curr->next = prev;
            prev = curr;
            curr = x;
        }
        sh = prev;
        st = findlast(prev);
        (left == 1)?head = sh:w->next = sh;
        st->next = z;
        return head;

    }
};