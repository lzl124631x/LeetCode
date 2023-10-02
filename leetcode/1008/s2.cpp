// OJ: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& A) {
        stack<pair<TreeNode*, int>> s;
        s.emplace(new TreeNode(A[0]), INT_MAX);
        auto root = s.top().first;
        for (int i = 1; i < A.size(); ++i) { 
            auto node = new TreeNode(A[i]);
            if (A[i] < s.top().first->val) {
                s.top().first->left = node;
                s.emplace(node, s.top().first->val);
            } else {
                while (A[i] > s.top().second) s.pop();
                s.top().first->right = node;
                s.emplace(node, s.top().second);
            }
        }
        return root;
    }
};