# [2095. Delete the Middle Node of a Linked List (Medium)](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

<p>You are given the <code>head</code> of a linked list. <strong>Delete</strong> the <strong>middle node</strong>, and return <em>the</em> <code>head</code> <em>of the modified linked list</em>.</p>

<p>The <strong>middle node</strong> of a linked list of size <code>n</code> is the <code>⌊n / 2⌋<sup>th</sup></code> node from the <b>start</b> using <strong>0-based indexing</strong>, where <code>⌊x⌋</code> denotes the largest integer less than or equal to <code>x</code>.</p>

<ul>
	<li>For <code>n</code> = <code>1</code>, <code>2</code>, <code>3</code>, <code>4</code>, and <code>5</code>, the middle nodes are <code>0</code>, <code>1</code>, <code>1</code>, <code>2</code>, and <code>2</code>, respectively.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/16/eg1drawio.png" style="width: 500px; height: 77px;">
<pre><strong>Input:</strong> head = [1,3,4,7,1,2,6]
<strong>Output:</strong> [1,3,4,1,2,6]
<strong>Explanation:</strong>
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/16/eg2drawio.png" style="width: 250px; height: 43px;">
<pre><strong>Input:</strong> head = [1,2,3,4]
<strong>Output:</strong> [1,2,4]
<strong>Explanation:</strong>
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/16/eg3drawio.png" style="width: 150px; height: 58px;">
<pre><strong>Input:</strong> head = [2,1]
<strong>Output:</strong> [2]
<strong>Explanation:</strong>
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Remove Nth Node From End of List (Medium)](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
* [Reorder List (Medium)](https://leetcode.com/problems/reorder-list/)
* [Remove Linked List Elements (Easy)](https://leetcode.com/problems/remove-linked-list-elements/)
* [Middle of the Linked List (Easy)](https://leetcode.com/problems/middle-of-the-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int getLength(ListNode *head) {
        int ans = 0;
        for (; head; ++ans, head = head->next);
        return ans;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode dummy, *p = &dummy;
        dummy.next = head;
        int len = getLength(head) / 2;
        for (int i = 0; i < len; ++i, p = p->next);
        p->next = p->next->next;
        return dummy.next;
    }
};
```

## Solution 2. Fast-Slow Pointers

```cpp
// OJ: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode dummy, *fast = &dummy, *slow = &dummy;
        dummy.next = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};
```