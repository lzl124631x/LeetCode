// OJ: https://leetcode.com/problems/maximum-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
    TreeNode *build(vector<int> &nums, int start, int end) {
        if (start >= end) return NULL;
        if (start + 1 == end) return new TreeNode(nums[start]);
        int best = start;
        for (int i = start; i < end; ++i) {
            if (nums[i] > nums[best]) best = i;
        }
        auto node = new TreeNode(nums[best]);
        node->left = build(nums, start, best);
        node->right = build(nums, best + 1, end);
        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
};