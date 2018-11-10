// OJ: https://leetcode.com/problems/split-linked-list-in-parts/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    int getLength(ListNode* root) {
        int len = 0;
        while (root) {
            root = root->next;
            ++len;
        }
        return len;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int N = getLength(root);
        int d = N / k, r = N % k;
        vector<ListNode*> ans;
        while (root) {
            ans.push_back(root);
            int len = d + (r ? 1 : 0);
            if (r > 0) --r;
            while (--len) root = root->next;
            ListNode *next = root->next;
            root->next = NULL;
            root = next;
        }
        while (ans.size() < k) ans.push_back(NULL);
        return ans;
    }
};