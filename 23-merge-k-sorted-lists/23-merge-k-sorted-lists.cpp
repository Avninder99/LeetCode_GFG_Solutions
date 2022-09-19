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
struct node_cmp
{
   bool operator()( const ListNode* a, const ListNode* b ) const 
   {
    return a->val > b->val;
   }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& l) {
        priority_queue<ListNode*, vector<ListNode*>, node_cmp>q1;
        int size = l.size();
        if(!size) return NULL;
        for(int i=0;i<size;i++){
            if(l[i]) q1.push(l[i]);
        }
        if(q1.empty()) return NULL;
        ListNode *curr = q1.top(), *head = curr, *temp = curr;
        q1.pop();
        if(temp->next) q1.push(temp->next);
        while(!q1.empty()){
            curr->next = q1.top();
            temp = q1.top()->next;
            q1.pop();
            if(temp) q1.push(temp);
            curr = curr->next;
        }
        return head;
    }
};