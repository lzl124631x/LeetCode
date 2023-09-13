// OJ: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        int maxSum = 0, ans = 0, lv = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int cnt = q.size(), sum = 0;
            while (cnt--) {
                auto node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum > maxSum) {
                maxSum = sum;
                ans = lv;
            }
            ++lv;
        }
        return ans;
    }
};