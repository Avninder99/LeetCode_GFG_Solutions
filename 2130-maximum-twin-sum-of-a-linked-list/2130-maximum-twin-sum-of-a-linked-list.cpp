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
        ListNode *curr = NULL, *prev = NULL, *endp = NULL, *sp = head, *fp = head->next, *temp = NULL;
        int counter = 0;
        while(fp != NULL && fp->next != NULL){
            counter++;
            sp = sp->next;
            fp = fp->next->next;
        }
        curr = sp->next;
        prev = sp;
        
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        endp = prev;
        int maxSum=0, temp1;
        
        while(true){
            temp1 = head->val + endp->val;
            if(temp1 > maxSum) maxSum = temp1;
            if(head->next == endp) break;
            head = head->next;
            endp = endp->next;
        }
        return maxSum;
    }
};