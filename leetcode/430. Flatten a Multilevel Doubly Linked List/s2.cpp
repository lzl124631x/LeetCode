// OJ: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    Node* flatten(Node* head) {
        for (auto p = head; p; p = p->next) {
            if (!p->child) continue;
            auto next = p->next;
            p->next = p->child;
            p->child->prev = p;
            auto q = p->child;
            while (q->next) q = q->next;
            q->next = next;
            if (next) next->prev = q;
            p->child = NULL;
        }
        return head;
    }
};