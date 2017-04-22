// OJ: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(logN)
class Solution {
private:
  int getLen(ListNode *head) {
    int len = 0;
    for (; head; head = head->next, ++len);
    return len;
  }
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return NULL;
    int len = getLen(head);
    ListNode *node = head, *prev = NULL;
    for (int n = len / 2; n; --n) {
      prev = node;
      node = node->next;
    }
    TreeNode *root = new TreeNode(node->val);
    if (prev) {
      prev->next = NULL;
      root->left = sortedListToBST(head);
    }
    root->right = sortedListToBST(node->next);
    return root;
  }
};