# [1474. Delete N Nodes After M Nodes of a Linked List (Easy)](https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/)

<p>Given the <code>head</code> of a linked list and two integers <code>m</code> and <code>n</code>. Traverse the linked list and remove some nodes in the following way:</p>

<ul>
	<li>Start with the head as the current node.</li>
	<li>Keep the first <code>m</code> nodes starting with the current node.</li>
	<li>Remove the next <code>n</code> nodes</li>
	<li>Keep repeating steps 2 and 3 until you reach the end of the list.</li>
</ul>

<p>Return the head of the modified list after removing the mentioned nodes.</p>


<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/06/sample_1_1848.png" style="width: 600px; height: 95px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5,6,7,8,9,10,11,12,13], m = 2, n = 3
<strong>Output:</strong> [1,2,6,7,11,12]
<strong>Explanation: </strong>Keep the first (m = 2) nodes starting from the head of the linked List  (1 -&gt;2) show in black nodes.
Delete the next (n = 3) nodes (3 -&gt; 4 -&gt; 5) show in read nodes.
Continue with the same procedure until reaching the tail of the Linked List.
Head of the linked list after removing nodes is returned.</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/06/06/sample_2_1848.png" style="width: 600px; height: 123px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5,6,7,8,9,10,11], m = 1, n = 3
<strong>Output:</strong> [1,5,9]
<strong>Explanation:</strong> Head of linked list after removing nodes is returned.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = [1,2,3,4,5,6,7,8,9,10,11], m = 3, n = 1
<strong>Output:</strong> [1,2,3,5,6,7,9,10,11]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> head = [9,3,7,7,9,10,8,2], m = 1, n = 2
<strong>Output:</strong> [9,7,8]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you solve this problem by modifying the list in-place?</p>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Remove Nth Node From End of List (Medium)](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
* [Remove Zero Sum Consecutive Nodes from Linked List (Medium)](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        auto p = head;
        while (p) {
            for (int i = 1; i < m && p; ++i) p = p->next;
            if (!p) break;
            auto tail = p;
            p = p->next;
            for (int i = 0; i < n && p; ++i) {
                auto rm = p;
                p = p->next;
                delete rm;
            }
            tail->next = p;
        }
        return head;
    }
};
```