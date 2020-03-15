// OJ: https://leetcode.com/problems/balance-a-binary-search-tree/
// Author: github.com/lzl124631x
// Time: O(H)
// Space: O(N)
class Solution {
    vector<int> v;
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    TreeNode *build(int start, int end) {
        if (start >= end) return NULL;
        int mid = (start + end) / 2;
        auto node = new TreeNode(v[mid]);
        node->left = build(start, mid);
        node->right = build(mid + 1, end);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, v.size());
    }
};