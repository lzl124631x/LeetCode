// OJ: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    vector<int> ans;
    TreeNode *target;
    int K;
    int inorder(TreeNode *root) {
        if (!root) return INT_MAX;
        if (root == target) return 1;
        int left = inorder(root->left);
        if (left != INT_MAX) {
            if (left < K) levelOrder(root->right, K - left - 1);
            else if (left == K) ans.push_back(root->val);
            return left + 1;
        }
        int right = inorder(root->right);
        if (right != INT_MAX) {
            if (right < K) {
                levelOrder(root->left, K - right - 1);
            } else if (right == K) ans.push_back(root->val);
            return right + 1;
        }
        return INT_MAX;
    }
    void levelOrder(TreeNode *root, int K) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                TreeNode *node = q.front();
                q.pop();
                if (level == K) ans.push_back(node->val);
                else {
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            ++level;
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        this->target = target;
        this->K = K;
        levelOrder(target, K);
        inorder(root);
        return ans;
    }
};