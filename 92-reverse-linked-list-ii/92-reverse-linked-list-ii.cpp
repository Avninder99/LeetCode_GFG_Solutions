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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp = NULL, *prev=NULL, *curr = head, *leftL=NULL, *nEnd=NULL;
        
        for(int i=0;i<left;i++){
            leftL = prev;
            prev = curr;
            curr = curr->next;
        }
        nEnd = prev;
        
        for(int i=0;i<right-left;i++){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        nEnd->next = curr;
        if(leftL)
            leftL->next = prev;
        
        if(left == 1) return prev;
        return head;
    }
};