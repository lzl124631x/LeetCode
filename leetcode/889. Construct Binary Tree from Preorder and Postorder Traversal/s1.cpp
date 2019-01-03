// OJ: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
    TreeNode *construct(vector<int> &pre, int preBegin, int preEnd,
                       vector<int> &post, int postBegin, int postEnd) {
        if (preBegin >= preEnd) return NULL;
        auto node = new TreeNode(pre[preBegin]);
        if (preBegin + 1 < preEnd) {
            int leftVal = pre[preBegin + 1];
            int postMid = find(post.begin() + postBegin, post.begin() + postEnd - 1, leftVal) - post.begin();
            int postLeftLength = postMid - postBegin + 1;
            node->left = construct(pre, preBegin + 1, preBegin + 1 + postLeftLength,
                                   post, postBegin, postMid + 1);
            node->right = construct(pre, preBegin + 1 + postLeftLength, preEnd,
                                   post, postMid + 1, postEnd - 1);
        }
        return node;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return construct(pre, 0, pre.size(), post, 0, post.size());
    }
};