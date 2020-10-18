# [92. Reverse Linked List II (Medium)](https://leetcode.com/problems/reverse-linked-list-ii/)

<p>Reverse a linked list from position <em>m</em> to <em>n</em>. Do it in one-pass.</p>

<p><strong>Note:&nbsp;</strong>1 ≤ <em>m</em> ≤ <em>n</em> ≤ length of list.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL, <em>m</em> = 2, <em>n</em> = 4
<strong>Output:</strong> 1-&gt;4-&gt;3-&gt;2-&gt;5-&gt;NULL
</pre>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Reverse Linked List (Easy)](https://leetcode.com/problems/reverse-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reverse-linked-list-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy, *p = &dummy;
        dummy.next = head;
        for (int i = 1; i < m; ++i) p = p->next;
        auto q = p->next, tail = q;
        for (int i = m; i <= n; ++i) {
            auto node = q;
            q = q->next;
            node->next = p->next;
            p->next = node;
        }
        tail->next = q;
        return dummy.next;
    }
};
```
