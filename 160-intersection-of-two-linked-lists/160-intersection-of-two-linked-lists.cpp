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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // follow up solution
        int len1=0, len2=0;
        ListNode *curr1=headA, *curr2=headB;
        while(curr1){
            curr1 = curr1->next;
            len1++;
        }
        while(curr2){
            curr2 = curr2->next;
            len2++;
        }
        int diff = max(len1,len2) - min(len1,len2);
        bool isF;
        if(len1 > len2){
            isF = true;
        }else{
            isF = false;
        }
        curr1=headA, curr2=headB;
        for(int i=0;i<diff;i++){
            if(isF) curr1 = curr1->next;
            else curr2 = curr2->next;
        }
        for(int i=0;i<min(len1,len2);i++){
            if(curr1 == curr2) return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return NULL;
    }
};