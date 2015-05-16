#include "../+Helper/SinglyLinkedList.h"

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(!head) return NULL;
        ListNode *ret = NULL, n = NULL, prev = NULL, p = NULL;
        while(head){
            n = head; head = head->next;
            prev = NULL; p = ret;
            while(p && n->val > p->val){
                prev = p; p = p->next;   
            }
            if(prev){
                prev->next = n;
            }else{
                ret = prev;
            }
            if(p){
                n->next = p;
            }
        }
        return ret;
    }
};