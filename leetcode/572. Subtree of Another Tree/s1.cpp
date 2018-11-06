// OJ: https://leetcode.com/problems/shortest-unsorted-continuous-subarray
// Author: github.com/lzl124631x
// Time: O(ST) where S and T are the node count of s and t.
// Space: O(H) where H is the height of s.
class Solution {
private:
    bool isSameTree(TreeNode* s, TreeNode* t) {
        return (!s && !t) || (s && t && s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right));
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return isSameTree(s, t) || (s && (isSubtree(s->left, t) || isSubtree(s->right, t)));
    }
};