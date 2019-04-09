// OJ: https://leetcode.com/problems/next-greater-node-in-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    ListNode *reverseList(ListNode *head) {
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> s;
        head = reverseList(head);
        while (head) {
            while (s.size() && head->val >= s.top()) s.pop();
            ans.push_back(s.size() ? s.top() : 0);
            s.push(head->val);
            head = head->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};