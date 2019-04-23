// OJ: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(H) where H is depth of tree
class Solution {
private:
    TreeNode *readNode(string &S, int &i) {
        int n = 0;
        for (; i < S.size() && isdigit(S[i]); ++i) n = 10 * n + S[i] - '0';
        return new TreeNode(n);
    }
    int readDash(string &S, int &i) {
        int cnt = 0;
        for (; i < S.size() && S[i] == '-'; ++i, ++cnt);
        return cnt;
    }
public:
    TreeNode* recoverFromPreorder(string S) {
        int i = 0, N = S.size();
        auto root = readNode(S, i);
        stack<TreeNode*> s;
        s.push(root);
        while (i < S.size()) {
            int dep = readDash(S, i);
            auto node = readNode(S, i);
            while (dep < s.size()) s.pop();
            auto p = s.top();
            if (p->left) p->right = node;
            else p->left = node;
            s.push(node);
        }
        return root;
    }
};