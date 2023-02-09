/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node*, int>nodeToIndex;
        vector<Node*>indexToNode;
        Node *curr = head, *newH = new Node(head->val), *h = newH;
        int i=0;
        while(curr){
            indexToNode.push_back(newH);
            newH->val = curr->val;
            if(curr->next) newH->next = new Node(100000);
            newH = newH->next;
            
            nodeToIndex[curr] = i++;
            curr = curr->next;
        }
        
        curr = head, newH = h;
        while(curr){
            if(curr->random){
                int t = nodeToIndex[curr->random];
                newH->random = indexToNode[t];
            }
            newH = newH->next;
            curr = curr->next;
        }
        return h;
    }
};