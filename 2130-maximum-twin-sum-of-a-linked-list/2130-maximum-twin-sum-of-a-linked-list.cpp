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
    int pairSum(ListNode* head) {
        ListNode *sptr = head, *fptr = head->next, *prev = NULL, *t, *tail;
        
        while(fptr && fptr->next){
            sptr = sptr->next;
            fptr = fptr->next->next;
        }
        prev = sptr;
        sptr = sptr->next;
        while(sptr){
            t = sptr->next;
            sptr->next = prev;
            prev = sptr;
            sptr = t;
        }
        tail = prev;
        
        int maxi = 0;
        while(head){
            maxi = max(maxi, head->val + tail->val);
            if(head->next == tail){
                break;
            }
            head = head->next;
            tail = tail->next;
        }
        
        return maxi;
    }
};