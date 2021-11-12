# [203. Remove Linked List Elements (Easy)](https://leetcode.com/problems/remove-linked-list-elements/)

<p>Given the <code>head</code> of a linked list and an integer <code>val</code>, remove all the nodes of the linked list that has <code>Node.val == val</code>, and return <em>the new head</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg" style="width: 500px; height: 142px;">
<pre><strong>Input:</strong> head = [1,2,6,3,4,5,6], val = 6
<strong>Output:</strong> [1,2,3,4,5]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> head = [], val = 1
<strong>Output:</strong> []
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = [7,7,7,7], val = 7
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 50</code></li>
	<li><code>0 &lt;= val &lt;= 50</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Remove Element (Easy)](https://leetcode.com/problems/remove-element/)
* [Delete Node in a Linked List (Easy)](https://leetcode.com/problems/delete-node-in-a-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/remove-linked-list-elements/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy, *tail = &dummy;
        while (head) {
            auto p = head;
            head = head->next;
            if (p->val == val) continue;
            tail->next = p;
            tail = p;
        }
        tail->next = NULL;
        return dummy.next;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/remove-linked-list-elements/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        for (auto p = &dummy; p && p->next;) {
            if (p->next->val != val) p = p->next;
            else p->next = p->next->next;
        }
        return dummy.next;
    }
};
```