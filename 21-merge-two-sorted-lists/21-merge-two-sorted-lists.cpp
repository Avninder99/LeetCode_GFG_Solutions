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
    ListNode* mergeTwoLists(ListNode* list1_ptr, ListNode* list2_ptr) {
        ListNode *new_list = NULL, *new_list_head = NULL;
        
        if(list1_ptr != NULL || list2_ptr != NULL){
            if(list1_ptr != NULL && list2_ptr != NULL){
                if(list1_ptr->val < list2_ptr->val){
                    new_list_head = list1_ptr;
                    list1_ptr = list1_ptr->next;
                }
                else{
                    new_list_head = list2_ptr;
                    list2_ptr = list2_ptr->next;
                }
            }else if(list1_ptr != NULL){
                new_list_head = list1_ptr;
                list1_ptr = list1_ptr->next;
            }else{
                new_list_head = list2_ptr;
                list2_ptr = list2_ptr->next;
            }
            new_list = new_list_head;
        }else{
            return new_list_head;
        }
        
        while(list1_ptr != NULL && list2_ptr != NULL){
            if(list1_ptr->val < list2_ptr->val){
                new_list->next = list1_ptr;
                list1_ptr = list1_ptr->next;
            }
            else{
                new_list->next = list2_ptr;
                list2_ptr = list2_ptr->next;
            }
            new_list = new_list->next;
        }
        
        if(list1_ptr != NULL){
            while(list1_ptr != NULL){
                new_list->next = list1_ptr;
                new_list = new_list->next;
                list1_ptr = list1_ptr->next;
            }
        }else{
            while(list2_ptr != NULL){
                new_list->next = list2_ptr;
                new_list = new_list->next;
                list2_ptr = list2_ptr->next;
            }  
        }
        return new_list_head;
        
    }
};