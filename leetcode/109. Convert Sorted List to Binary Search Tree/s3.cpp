// OJ: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
// Ref: https://discuss.leetcode.com/topic/8141/share-my-o-1-space-and-o-n-time-java-code
class Solution {
private:
  ListNode *head;
  int getLen(ListNode *head) {
    int len = 0;
    for (; head; head = head->next, ++len);
      return len;
  }
  TreeNode *build(int begin, int end) {
    if (begin >= end) return NULL;
    int mid = (begin + end) / 2;
    TreeNode *left = build(begin, mid);
    TreeNode *root = new TreeNode(head->val);
    head = head->next;
    root->left = left;
    root->right = build(mid + 1, end);
    return root;
  }
public:
  TreeNode* sortedListToBST(ListNode* head) {
    this->head = head;
    return build(0, getLen(head));
  }
};