// OJ: https://leetcode.com/problems/cousins-in-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val == y) return false;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.emplace((TreeNode*)NULL, root);
        while (q.size()) {
            int cnt = q.size();
            TreeNode *a = NULL, *b = NULL;
            while (cnt--) {
                auto p = q.front();
                q.pop();
                if (p.second->val == x) a = p.first;
                if (p.second->val == y) b = p.first;
                if (p.second->left) q.emplace(p.second, p.second->left);
                if (p.second->right) q.emplace(p.second, p.second->right);
            }
            if (a || b) return a && b && a != b;
        }
        return false;
    }
};