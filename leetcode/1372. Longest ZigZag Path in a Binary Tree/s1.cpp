// OJ: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int A = 0;
    pair<int, int> postorder(TreeNode* root)  {
        if (!root || (!root->left && !root->right)) return { 0, 0 };
        pair<int, int> ans;
        if (root->left) {
            auto left = postorder(root->left);
            ans.first = 1 + left.second;
        }
        if (root->right) {
            auto right = postorder(root->right);
            ans.second = 1 + right.first;
        }
        A = max({ A, ans.first, ans.second });
        return ans;
    }
public:
    int longestZigZag(TreeNode* root) {
        postorder(root);
        return A;
    }
};