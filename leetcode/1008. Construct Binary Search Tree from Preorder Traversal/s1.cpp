// OJ: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
    TreeNode* construct(vector<int> &preorder, int begin, int end) {
        if (begin >= end) return NULL;
        auto root = new TreeNode(preorder[begin]);
        int i = begin + 1;
        while (i < end && preorder[i] < preorder[begin]) ++i;
        root->left = construct(preorder, begin + 1, i);
        root->right = construct(preorder, i, end);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, 0, preorder.size());
    }
};