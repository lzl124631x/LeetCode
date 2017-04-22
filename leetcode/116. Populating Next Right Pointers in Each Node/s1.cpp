// OJ: https://leetcode.com/problems/populating-next-right-pointers-in-each-node
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode *first = root;
    while (first && first->left) {
      root = first;
      while (root) {
        root->left->next = root->right;
        if (root->next) root->right->next = root->next->left;
        root = root->next;
      }
      first = first->left;
    }
  }
};