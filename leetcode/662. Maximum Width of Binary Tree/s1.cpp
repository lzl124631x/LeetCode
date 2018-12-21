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
            int cnt = q.size(), minVal = INT_MAX, maxVal = INT_MIN;
            while (cnt--) {
                auto &p = q.front();
                q.pop();
                root = p.first;
                minVal = min(minVal, p.second);
                maxVal = max(maxVal, p.second);
                if (root->left) q.push(make_pair(root->left, p.second * 2));
                if (root->right) q.push(make_pair(root->right, p.second * 2 + 1));
            }
            ans = max(ans, maxVal - minVal + 1);
        }
        return ans;
    }
};