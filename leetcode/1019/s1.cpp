// OJ: https://leetcode.com/problems/next-greater-node-in-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    ListNode *reverseList(ListNode *head) {
        ListNode h;
        while (head) {
            auto node = head;
            head = head->next;
            node->next = h.next;
            h.next = node;
        }
        return h.next;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> s;
        head = reverseList(head);
        for (; head; head = head->next) {
            while (s.size() && s.top() <= head->val) s.pop();
            ans.push_back(s.size() ? s.top() : 0);
            s.push(head->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};