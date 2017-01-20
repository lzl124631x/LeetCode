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
    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int len = getLength(head);
        k %= len;
        if (!k) return head;
        ListNode *p = head, *newHead, *newTail;
        k = len - k - 1;
        while (k--) p = p->next;
        newTail = p;
        p = newHead = p->next;
        newTail->next = NULL;
        while (p->next) p = p->next;
        p->next = head;
        return newHead;
    }
};