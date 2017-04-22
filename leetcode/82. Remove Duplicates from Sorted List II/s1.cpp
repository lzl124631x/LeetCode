// OJ: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0), *tail = &dummy;
    while (head) {
      if (head->next && head->next->val == head->val) {
        int val = head->val;
        while (head && head->val == val) {
          ListNode *p = head;
          head = head->next;
          delete p;
        }
      } else {
        tail->next = head;
        tail = tail->next;
        head = head->next;
      }
    }
    tail->next = NULL;
    return dummy.next;
  }
};