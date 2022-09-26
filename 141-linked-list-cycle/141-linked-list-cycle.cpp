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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *sptr=head, *fptr=head->next;
        while(fptr){
            if(sptr == fptr) return true;
            sptr = sptr->next;
            fptr = fptr->next;
            if(fptr) fptr = fptr->next;
        }
        return false;
    }
};