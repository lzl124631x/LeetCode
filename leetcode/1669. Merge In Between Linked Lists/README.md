# [1669. Merge In Between Linked Lists (Medium)](https://leetcode.com/problems/merge-in-between-linked-lists/)

<p>You are given two linked lists: <code>list1</code> and <code>list2</code> of sizes <code>n</code> and <code>m</code> respectively.</p>

<p>Remove <code>list1</code>'s nodes from the <code>a<sup>th</sup></code> node to the <code>b<sup>th</sup></code> node, and put <code>list2</code> in their place.</p>

<p>The blue edges and nodes in the following figure incidate the result:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/fig1.png" style="height: 130px; width: 504px;">
<p><em>Build the result list and return its head.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/merge_linked_list_ex1.png" style="width: 406px; height: 140px;">
<pre><strong>Input:</strong> list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
<strong>Output:</strong> [0,1,2,1000000,1000001,1000002,5]
<strong>Explanation:</strong> We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/merge_linked_list_ex2.png" style="width: 463px; height: 140px;">
<pre><strong>Input:</strong> list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
<strong>Output:</strong> [0,1,1000000,1000001,1000002,1000003,1000004,6]
<strong>Explanation:</strong> The blue edges and nodes in the above figure indicate the result.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= list1.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= a &lt;= b &lt; list1.length - 1</code></li>
	<li><code>1 &lt;= list2.length &lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

## Solution 1.

Find the following pointers:
* `p` where `p->next` points to `a`th node.
* `q` where `p` points to `b`th node.

Then we can stitch them together by assigning:
* `B` to `p->next`
* `q->next` to the `next` pointer of `B`'s tail node.

```cpp
// OJ: https://leetcode.com/problems/merge-in-between-linked-lists/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* mergeInBetween(ListNode* A, int a, int b, ListNode* B) {
        ListNode *q = A, *p = NULL;
        for (int i = 0; i < b; ++i) {
            if (i == a - 1) p = q;
            q = q->next;
        }
        p->next = B;
        while (B->next) B = B->next;
        B->next = q->next;
        return A;
    }
};
```