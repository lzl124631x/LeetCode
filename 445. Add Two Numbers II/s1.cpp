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
    int getLength (ListNode *head) {
        int n = 0;
        while (head) {
            head = head->next;
            ++n;
        }
        return n;
    }
    ListNode *reverse(ListNode *head) {
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
        ListNode *head = NULL;
        int n1 = getLength(l1), n2 = getLength(l2);
        if (n1 < n2) {
            swap(l1, l2);
            swap(n1, n2);
        }
        while (n1 > n2) {
            ListNode *p = new ListNode(l1->val);
            p->next = head;
            head = p;
            l1 = l1->next;
            --n1;
        }
        while (l1) {
            int carry = l1->val + l2->val;
            ListNode *p = new ListNode(carry % 10);
            p->next = head;
            head = p;
            while (carry /= 10) {
                if (p->next) {
                    carry += p->next->val;
                    p->next->val = carry % 10;
                    p = p->next;
                } else {
                    p->next = new ListNode(carry);
                }
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return reverse(head);
    }
};