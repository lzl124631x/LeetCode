// OJ: https://leetcode.com/problems/plus-one-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    ListNode *reverse(ListNode *head) {
        ListNode dummy(0);
        while (head) {
            auto p = head;
            head = head->next;
            p->next = dummy.next;
            dummy.next = p;
        }
        return dummy.next;
    }
public:
    ListNode* plusOne(ListNode* head) {
        head = reverse(head);
        ListNode *p = head;
        int carry = 1;
        while (carry) {
            p->val++;
            carry = p->val / 10;
            p->val %= 10;
            if (!p->next) break;
            p = p->next;
        }
        if (carry) p->next = new ListNode(1);
        return reverse(head);
    }
};