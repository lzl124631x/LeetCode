// OJ: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    vector<int> v;
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i = 0, j = v.size() - 1;
        while (i < j) {
            int sum = v[i] + v[j];
            if (sum == k) return true;
            if (sum > k) --j;
            else ++i;
        }
        return false;
    }
};