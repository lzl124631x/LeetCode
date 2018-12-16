// OJ: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool onlyLeafNow = false;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                root = q.front();
                q.pop();
                if (!root->left && root->right) return false;
                if (onlyLeafNow && (root->left || root->right)) return false;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
                if (!root->left || !root->right) onlyLeafNow = true;
            }
        }
        return true;
    }
};