// OJ: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> parent;
    void dfs(TreeNode *node, TreeNode *par) {
        if (!node) return;
        parent[node] = par;
        if (node->left) dfs(node->left, node);
        if (node->right) dfs(node->right, node);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, NULL);
        unordered_set<TreeNode*> seen;
        seen.insert(NULL);
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(target);
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                root = q.front();
                seen.insert(root);
                q.pop();
                if (!K) ans.push_back(root->val);
                else {
                    if (seen.find(root->left) == seen.end()) q.push(root->left);
                    if (seen.find(root->right) == seen.end()) q.push(root->right);
                    if (seen.find(parent[root]) == seen.end()) q.push(parent[root]);
                }
            }
            --K;
        }
        return ans;
    }
};