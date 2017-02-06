/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverse(ListNode *head) {
        ListNode newHead(0);
        while (head) {
            ListNode *p = head;
            head = head->next;
            p->next = newHead.next;
            newHead.next = p;
        }
        return newHead.next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int carry = 0;
        ListNode head(0), *tail = &head;
        while (l1 || l2 || carry) {
            if (l1) {
                carry += l1->val; 
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            tail->next = new ListNode(carry % 10);
            tail = tail->next;
            carry /= 10;
        }
        return reverse(head.next);
    }
};