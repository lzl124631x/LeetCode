// OJ: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        while (q.size()) {
            int nextCnt = 0;
            vector<int> level;
            while (cnt--) {
                root = q.front();
                q.pop();
                level.push_back(root->val);
                if (root->left) {
                    ++nextCnt;
                    q.push(root->left);
                }
                if (root->right) {
                    ++nextCnt;
                    q.push(root->right);
                }
            }
            ans.push_back(level);
            cnt = nextCnt;
        }
        return ans;
    }
};