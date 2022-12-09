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
    ListNode* partition(ListNode* head, int x) {
        ListNode *nh = new ListNode(-200, head), *ptr = nh, *itr = NULL, *t;
        while(ptr->next && ptr->next->val < x){
            ptr = ptr->next;
        }
        
        itr = ptr->next;
        if(itr == NULL) return head;
        
        while(itr && itr->next){
            if(itr->next->val < x){
                t = itr->next;
                itr->next = t->next;
                t->next = ptr->next;
                ptr->next = t;
                ptr = ptr->next;
            }else{
                itr = itr->next;
            }
        }
        return nh->next;
    }
};