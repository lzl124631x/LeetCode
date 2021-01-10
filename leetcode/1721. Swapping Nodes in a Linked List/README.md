# [1721. Swapping Nodes in a Linked List (Medium)](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)

<p>You are given the <code>head</code> of a linked list, and an integer <code>k</code>.</p>

<p>Return <em>the head of the linked list after <strong>swapping</strong> the values of the </em><code>k<sup>th</sup></code> <em>node from the beginning and the </em><code>k<sup>th</sup></code> <em>node from the end (the list is <strong>1-indexed</strong>).</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg" style="width: 722px; height: 202px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [1,4,3,2,5]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> head = [7,9,6,6,7,8,3,0,9,5], k = 5
<strong>Output:</strong> [7,9,6,6,8,7,3,0,9,5]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = [1], k = 1
<strong>Output:</strong> [1]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> head = [1,2], k = 1
<strong>Output:</strong> [2,1]
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> head = [1,2,3], k = 2
<strong>Output:</strong> [1,2,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>n</code>.</li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Remove Nth Node From End of List (Medium)](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
* [Swap Nodes in Pairs (Medium)](https://leetcode.com/problems/swap-nodes-in-pairs/)
* [Reverse Nodes in k-Group (Hard)](https://leetcode.com/problems/reverse-nodes-in-k-group/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int getLength(ListNode *head) {
        int len = 0;
        for (; head; head = head->next) ++len;
        return len;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len = getLength(head), r = len - k + 1;
        if (r == k) return head;
        if (r < k) swap(r, k);
        auto p = head, q = head;
        while (--k) p = p->next;
        while (--r) q = q->next;
        swap(p->val, q->val);
        return head;
    }
};
```