// OJ: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H) where H is the max depth of the child hierarchy.
class Solution {
    pair<Node*, Node*> f(Node* head) {
        if (!head) return {NULL, NULL};
        pair<Node*, Node*> p = {head, NULL};
        while (head) {
            auto next = head->next;
            auto last = head;
            if (head->child) {
                auto q = f(head->child);
                head->next = q.first;
                q.first->prev = head;
                if (next) {
                    q.second->next = next;
                    next->prev = q.second;
                } else last = q.second;
                head->child = NULL;
            }
            if (!next) p.second = last;
            head = next;
        }
        return p;
    }
public:
    Node* flatten(Node* head) {
        return f(head).first;
    }
};