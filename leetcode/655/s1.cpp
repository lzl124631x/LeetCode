// OJ: https://leetcode.com/problems/print-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    int getDepth(TreeNode *root) {
        queue<TreeNode*> q;
        int d = 0;
        q.push(root);
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                root = q.front();
                q.pop();
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            ++d;
        }
        return d;
    }
    void dfs(TreeNode *root, int start, int end, int depth, vector<vector<string>> &ans) {
        if (!root) return;
        int M = (start + end) / 2;
        ans[depth][M] = to_string(root->val);
        dfs(root->left, start, M, depth + 1, ans);
        dfs(root->right, M + 1, end, depth + 1, ans);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int d = getDepth(root), N = (1 << d) - 1;
        vector<vector<string>> ans(d, vector<string>(N));
        dfs(root, 0, N, 0, ans);
        return ans;
    }
};