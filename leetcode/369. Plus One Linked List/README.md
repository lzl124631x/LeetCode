# [369. Plus One Linked List (Medium)](https://leetcode.com/problems/plus-one-linked-list/)

<p>Given a non-negative integer represented as <b>non-empty</b> a singly linked list of digits, plus one to the integer.</p>

<p>You may assume the integer do not contain any leading zero, except the number 0 itself.</p>

<p>The digits are stored such that the most significant digit is at the head of the list.</p>

<div>
<p><strong>Example :</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,2,3]</span>
<strong>Output: </strong><span id="example-output-1">[1,2,4]</span>
</pre>
</div>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Plus One (Easy)](https://leetcode.com/problems/plus-one/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/plus-one-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    ListNode *reverse(ListNode *head) {
        ListNode dummy(0);
        while (head) {
            auto p = head;
            head = head->next;
            p->next = dummy.next;
            dummy.next = p;
        }
        return dummy.next;
    }
public:
    ListNode* plusOne(ListNode* head) {
        head = reverse(head);
        ListNode *p = head;
        int carry = 1;
        while (carry) {
            p->val++;
            carry = p->val / 10;
            p->val %= 10;
            if (!p->next) break;
            p = p->next;
        }
        if (carry) p->next = new ListNode(1);
        return reverse(head);
    }
};
```