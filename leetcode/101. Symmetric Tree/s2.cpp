// OJ: https://leetcode.com/problems/symmetric-tree
// Auther: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if(!root) return true;
    stack<TreeNode*> q1, q2;
    q1.push(root); q2.push(root);
    while(!q1.empty() && !q2.empty()){
      TreeNode *r1 = q1.top(), *r2 = q2.top();
      q1.pop(); q2.pop();
      if(r1->val != r2->val) return false;
      if(r1->left && !r2->right || !r1->left && r2->right) return false;
      if(r1->right && !r2->left || !r1->right && r2->left) return false;
      if(r1->right) q1.push(r1->right);
      if(r1->left) q1.push(r1->left);
      if(r2->left) q2.push(r2->left);
      if(r2->right) q2.push(r2->right);
    }
    if(!q1.empty() || !q2.empty()) return false;
    return true;
  }
};