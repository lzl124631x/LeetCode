// OJ: https://leetcode.com/problems/next-greater-node-in-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> s;
        while (head) {
            ans.push_back(0);
            int i = 2;
            while (s.size() && s.top() < head->val) {
                ans[ans.size() - i++] = head->val;
                s.pop();
            }
            s.push(head->val);
            head = head->next;
        }
        return ans;
    }
};