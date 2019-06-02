// OJ: https://leetcode.com/problems/merge-k-sorted-lists/
// Author: github.com/lzl124631x
// Time: O(NlogK)
// Space: O(1)
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode head(0), *tail = &head;
        while (a && b) {
            if (a->val < b->val) { tail->next = a; a = a->next; }
            else { tail->next = b; b = b->next; }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return head.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        for (int N = lists.size(); N > 1; N = (N + 1) / 2) {
            for (int i = 0; i < N / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[N - 1 - i]);
            }
        }
        return lists[0];
    }
};