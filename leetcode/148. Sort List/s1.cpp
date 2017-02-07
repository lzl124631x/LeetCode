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
    void quickSort(ListNode *prevBegin, ListNode *begin, ListNode *end) {
        if (begin == end) return;
        ListNode *pivot = begin, *prevCur = pivot, *equalTail = pivot, *cur = pivot->next;
        while (cur != end) {
            if (cur->val < pivot->val) {
                prevCur->next = cur->next;
                cur->next = prevBegin->next;
                prevBegin->next = cur;
            } else if (cur->val == pivot->val && equalTail != prevCur) {
                prevCur->next = cur->next;
                cur->next = equalTail->next;
                equalTail->next = cur;
                equalTail = cur;
            } else {
                prevCur = cur;
            }
            cur = prevCur->next;
        }
        quickSort(prevBegin, prevBegin->next, pivot);
        quickSort(equalTail, equalTail->next, end);
    }
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        quickSort(&dummy, head, NULL);
        head = dummy.next;
        return head;
    }
};