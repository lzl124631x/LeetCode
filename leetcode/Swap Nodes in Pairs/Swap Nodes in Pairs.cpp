class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *prev, *p, *q;
        prev = NULL; p = head;
        while(p && p->next){
            q = p->next;
            if(prev){
                prev->next = q;
            }else{
                head = q;
            }
            p->next = q->next;
            q->next = p;
            prev = p;
            p = p->next;
        }
        return head;
    }
};