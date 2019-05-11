// OJ: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    int sum = 0, num = 0;
public:
    int sumRootToLeaf(TreeNode* root) {
        if (!root) return 0;
        num = num * 2 + root->val;
        if (!root->left && !root->right) sum += num;
        else {
            sumRootToLeaf(root->left);
            sumRootToLeaf(root->right);
        }
        num /= 2;
        return sum;
    }
};