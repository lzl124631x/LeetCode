// OJ: https://leetcode.com/problems/all-possible-full-binary-trees/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N % 2 == 0) return {};
        if (N == 1) return { new TreeNode(0) };
        vector<TreeNode*> ans;
        for (int i = 1; i <= N - 2; i += 2) {
            auto lefts = allPossibleFBT(i);
            auto rights = allPossibleFBT(N - i - 1);
            for (auto left : lefts) {
                for (auto right : rights) {
                    auto root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};