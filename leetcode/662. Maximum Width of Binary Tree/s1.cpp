// OJ: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int ans = INT_MIN;
        while (q.size()) {
            int cnt = q.size(), left, right;
            for (int i = 0; i < cnt; ++i) {
                auto &p = q.front();
                q.pop();
                root = p.first;
                if (i == 0) left = p.second;
                if (i == cnt - 1) right = p.second;
                if (root->left) q.push(make_pair(root->left, p.second * 2));
                if (root->right) q.push(make_pair(root->right, p.second * 2 + 1));
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};