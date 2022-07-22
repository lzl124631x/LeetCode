# [86. Partition List (Medium)](https://leetcode.com/problems/partition-list/)

<p>Given the <code>head</code> of a linked list and a value <code>x</code>, partition it such that all nodes <strong>less than</strong> <code>x</code> come before nodes <strong>greater than or equal</strong> to <code>x</code>.</p>

<p>You should <strong>preserve</strong> the original relative order of the nodes in each of the two partitions.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/partition.jpg" style="width: 662px; height: 222px;">
<pre><strong>Input:</strong> head = [1,4,3,2,5,2], x = 3
<strong>Output:</strong> [1,2,2,4,3,5]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> head = [2,1], x = 2
<strong>Output:</strong> [1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 200]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li><code>-200 &lt;= x &lt;= 200</code></li>
</ul>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Partition Array According to Given Pivot (Medium)](https://leetcode.com/problems/partition-array-according-to-given-pivot/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/partition-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode ltHead, *ltTail = &ltHead, geHead, *geTail = &geHead;
        while (head) {
            auto n = head;
            head = head->next;
            if (n->val < x) {
                ltTail->next = n;
                ltTail = n;
            } else {
                geTail->next = n;
                geTail = n;
            }
        }
        ltTail->next = geHead.next;
        geTail->next = nullptr;
        return ltHead.next;
    }
};
```