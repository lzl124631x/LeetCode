// OJ: https://leetcode.com/problems/linked-list-components/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s(G.begin(), G.end());
        int ans = 0;
        while (true) {
            while (head && s.find(head->val) == s.end()) head = head->next;
            if (!head) break;
            ++ans;
            while (head && s.find(head->val) != s.end()) head = head->next;
        }
        return ans;
    }
};