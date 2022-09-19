/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // follow up solution
        if(!head) return NULL;
        ListNode *sptr=head, *fptr=head->next;
        while(fptr != NULL && sptr != fptr){
            sptr = sptr->next;
            fptr = fptr->next;
            if(fptr) fptr = fptr->next;
        }
        if(!fptr) return NULL;
        sptr = sptr->next;
        fptr = head;
        while(sptr != fptr){
            sptr = sptr->next;
            fptr = fptr->next;
        }
        return sptr;
    }
};