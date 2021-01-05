# [82. Remove Duplicates from Sorted List II (Medium)](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

<p>Given the <code>head</code> of a sorted linked list, <em>delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list</em>. Return <em>the linked list <strong>sorted</strong> as well</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg" style="width: 500px; height: 142px;">
<pre><strong>Input:</strong> head = [1,2,3,3,4,4,5]
<strong>Output:</strong> [1,2,5]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg" style="width: 500px; height: 205px;">
<pre><strong>Input:</strong> head = [1,1,1,2,3]
<strong>Output:</strong> [2,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 300]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li>The list is guaranteed to be <strong>sorted</strong> in ascending order.</li>
</ul>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Remove Duplicates from Sorted List (Easy)](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode h, *tail = &h;
        while (head) {
            if (head->next == NULL || head->next->val != head->val) {
                tail->next = head;
                tail = head;
                head = head->next;
            } else {
                int val = head->val;
                while (head && head->val == val) head = head->next;
            }
        }
        tail->next = NULL;
        return h.next;
    }
};
```