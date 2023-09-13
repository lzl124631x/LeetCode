# [2816. Double a Number Represented as a Linked List (Medium)](https://leetcode.com/problems/double-a-number-represented-as-a-linked-list)

<p>You are given the <code>head</code> of a <strong>non-empty</strong> linked list representing a non-negative integer without leading zeroes.</p>
<p>Return <em>the </em><code>head</code><em> of the linked list after <strong>doubling</strong> it</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/05/28/example.png" style="width: 401px; height: 81px;">
<pre><strong>Input:</strong> head = [1,8,9]
<strong>Output:</strong> [3,7,8]
<strong>Explanation:</strong> The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/05/28/example2.png" style="width: 401px; height: 81px;">
<pre><strong>Input:</strong> head = [9,9,9]
<strong>Output:</strong> [1,9,9,8]
<strong>Explanation:</strong> The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>The number of nodes in the list is in the range <code>[1, 10<sup>4</sup>]</code></li>
	<li><font face="monospace"><code>0 &lt;= Node.val &lt;= 9</code></font></li>
	<li>The input is generated such that the list represents a number that does not have leading zeros, except the number <code>0</code> itself.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Math](https://leetcode.com/tag/math/), [Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Add Two Numbers (Medium)](https://leetcode.com/problems/add-two-numbers/)
* [Plus One Linked List (Medium)](https://leetcode.com/problems/plus-one-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    ListNode *reverseList(ListNode *head) {
        ListNode dummy;
        while (head) {
            auto p = head;
            head = head->next;
            p->next = dummy.next;
            dummy.next = p;
        }
        return dummy.next;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        int carry = 0;
        ListNode *prev = nullptr;
        for (auto p = head; p; ) {
            carry += p->val * 2;
            p->val = carry % 10;
            carry /= 10;
            prev = p;
            p = p->next;
        }
        if (carry) prev->next = new ListNode(carry);
        return reverseList(head);
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode *prev = nullptr;
        for (auto p = head; p; ) {
            int n = p->val * 2;
            if (n / 10) {
                if (prev) prev->val++;
                else {
                    auto h = new ListNode(1);
                    h->next = head;
                    head = h;
                }
            }
            p->val = n % 10;
            prev = p;
            p = p->next;
        }
        return head;
    }
};
```