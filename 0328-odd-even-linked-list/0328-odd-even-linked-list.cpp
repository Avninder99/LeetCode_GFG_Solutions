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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* ehead = new ListNode(-1), *h1 = head, *h2 = ehead;
        while(head && head->next){
            ehead->next = head->next;
            ehead = ehead->next;
            head->next = head->next->next;
            if(head->next) head = head->next;
        }
        ehead->next = NULL;
        head->next = h2->next;
        return h1;
    }
};