// OJ: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(H)
class Solution {
    int curLevel;
    TreeNode *curNode;
    void dfs(istringstream &in, TreeNode *parent, int level) {
        if (in.eof()) return;
        curLevel = 0;
        for (; in.peek() == '-'; in.get(), ++curLevel);
        int n;
        in >> n;
        curNode = new TreeNode(n);
        while (curNode && curLevel == level) {
            if (!parent->left) parent->left = curNode;
            else parent->right = curNode;
            auto node = curNode;
            curNode = NULL;
            dfs(in, node, level + 1);
        }
    }
public:
    TreeNode* recoverFromPreorder(string S) {
        istringstream in(S);
        int n;
        in >> n;
        auto root = new TreeNode(n);
        dfs(in, root, 1);
        return root;
    }
};