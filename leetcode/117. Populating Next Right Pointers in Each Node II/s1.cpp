// OJ: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode *first = root;
    while (first) {
      TreeLinkNode *parent = first, *head = NULL, *tail = NULL;
      while (parent) {
        if (parent->left) {
          if (tail) tail->next = parent->left;
          else head = parent->left;
          tail = parent->left;
        }
        if (parent->right) {
          if (tail) tail->next = parent->right;
          else head = parent->right;
          tail = parent->right;
        }
        parent = parent->next;
      }
      first = head;
    }
  }
};