// OJ: https://leetcode.com/problems/reorder-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    ListNode *reverseList(ListNode *head) {
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
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode *fast = head, *slow = head, *rightHead;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        rightHead = slow->next;
        slow->next = NULL;
        rightHead = reverseList(rightHead);
        while (rightHead) {
            ListNode *p = rightHead;
            rightHead = rightHead->next;
            p->next = head->next;
            head->next = p;
            head = p->next;
        }
    }
};