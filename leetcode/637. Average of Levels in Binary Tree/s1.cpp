// OJ: https://leetcode.com/problems/average-of-levels-in-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            double cnt = q.size(), sum = 0;
            for (int i = 0; i < cnt; ++i) {
                root = q.front();
                q.pop();
                sum += root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            ans.push_back(sum / cnt);
        }
        return ans;
    }
};