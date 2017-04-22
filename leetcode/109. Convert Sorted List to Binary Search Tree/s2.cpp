// OJ: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(logN)
// Ref: https://discuss.leetcode.com/topic/35997/share-my-java-solution-1ms-very-short-and-concise
class Solution {
private:
  TreeNode *build(ListNode *head, ListNode *end) {
    if (head == end) return NULL;
    auto slow = head, fast = head;
    while (fast != end && fast->next != end) {
      fast = fast->next->next;
      slow = slow->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    root->left = build(head, slow);
    root->right = build(slow->next, end);
    return root;
  }
public:
  TreeNode* sortedListToBST(ListNode* head) {
    return build(head, NULL);
  }
};