// OJ: https://leetcode.com/problems/binary-search-tree-iterator/
// Author: github.com/lzl124631x
// Time: O(1) amortized
// Space: O(logN)
class BSTIterator {
private:
    stack<TreeNode*> s;
    void pushNodes(TreeNode *node) {
        while (node) {
            s.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushNodes(root);
    }
    int next() {
        auto node = s.top();
        s.pop();
        if (node->right) pushNodes(node->right);
        return node->val;
    }
    bool hasNext() {
        return s.size();
    }
};