// OJ: https://leetcode.com/problems/construct-string-from-binary-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
  string tree2str(TreeNode* t) {
    if (!t) return "";
    string left = tree2str(t->left), right = tree2str(t->right);
    string ans = to_string(t->val);
    if (left.size() || right.size())  ans += "(" + left + ")";
    if (right.size()) ans += "(" + right + ")";
    return ans;
  }
};