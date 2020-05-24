// OJ: https://leetcode.com/problems/next-greater-node-in-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> s;
        for (; head; head = head->next) ans.push_back(head->val);
        for (int i = 0; i < ans.size(); ++i) {
            while (s.size() && ans[s.top()] < ans[i]) {
                ans[s.top()] = ans[i];
                s.pop();
            }
            s.push(i);
        }
        for (; s.size(); s.pop()) ans[s.top()] = 0;
        return ans;
    }
};