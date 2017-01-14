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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0), *tail = &head;
        while (l1 && l2) {
            if (l1->val < l2->val) { tail->next = l1; l1 = l1->next; }
            else { tail->next = l2; l2 = l2->next; }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return head.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int N = lists.size();
        while (N > 1) {
            for (int i = 0; i < N / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[N - 1 - i]);
            }
            N = (N + 1) / 2;
        }
        return lists[0];
    }
};