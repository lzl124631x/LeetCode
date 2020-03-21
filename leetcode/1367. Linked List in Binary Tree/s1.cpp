// OJ: https://leetcode.com/problems/linked-list-in-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N * min(L, H))
// Space: O(H)
class Solution {
    bool dfs(ListNode *head, TreeNode *root) {
        if (!head) return true;
        if (!root) return false;
        return head->val == root->val && (dfs(head->next, root->left) || dfs(head->next, root->right));
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};