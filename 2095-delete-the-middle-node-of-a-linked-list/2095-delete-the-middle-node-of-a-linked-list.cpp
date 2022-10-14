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
    ListNode* deleteMiddle(ListNode* head) {
        if(!(head->next)) return NULL;
        ListNode *sptr=head, *fptr=head->next, *temp=NULL;
        while(fptr != NULL){
            temp = sptr;
            sptr = sptr->next;
            fptr = fptr->next;
            if(fptr) fptr = fptr->next;
        }
        temp->next = sptr->next;
        delete sptr;
        return head;
    }
};