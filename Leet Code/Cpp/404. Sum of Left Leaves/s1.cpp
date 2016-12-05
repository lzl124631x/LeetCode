class Solution {
private:
    int rec (TreeNode *node, TreeNode *p) {
        if (!node) return 0;
        if (!node->left && !node->right && p && p->left == node) return node->val;
        return rec(node->left, node) + rec(node->right, node);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return rec(root, NULL);
    }
};