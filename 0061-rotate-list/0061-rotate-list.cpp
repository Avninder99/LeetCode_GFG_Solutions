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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode *curr = head;
        int size = 0;
        while(curr){
            size++;
            curr = curr->next;
        }
        
        k %= size;
        if(k == 0) return head;
        
        ListNode *sptr = head, *fptr = head;
        
        while(k--){
            fptr = fptr->next;
        }
        
        while(fptr->next){
            sptr = sptr->next;
            fptr = fptr->next;
        }
        
        curr = sptr->next;
        sptr->next = NULL;
        fptr->next = head;
        return curr;
    }
};