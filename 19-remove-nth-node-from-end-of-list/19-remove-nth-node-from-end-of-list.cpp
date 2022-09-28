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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *target=head , *h2=head, *prev=NULL;
        int itr = 1;
        while(head->next){
            
            if(itr >= n){
                prev = target;
                target = target->next;

            }
            head = head->next;
            itr++;
        }
        if(!prev){
            h2 = h2->next;
        }else{
            prev->next = target->next;
            delete target;
        }
        return h2;
    }
};