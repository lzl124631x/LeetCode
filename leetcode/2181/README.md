# [2181. Merge Nodes in Between Zeros (Medium)](https://leetcode.com/problems/merge-nodes-in-between-zeros/)

<p>You are given the <code>head</code> of a linked list, which contains a series of integers <strong>separated</strong> by <code>0</code>'s. The <strong>beginning</strong> and <strong>end</strong> of the linked list will have <code>Node.val == 0</code>.</p>

<p>For <strong>every </strong>two consecutive <code>0</code>'s, <strong>merge</strong> all the nodes lying in between them into a single node whose value is the <strong>sum</strong> of all the merged nodes. The modified list should not contain any <code>0</code>'s.</p>

<p>Return <em>the</em> <code>head</code> <em>of the modified linked list</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/02/ex1-1.png" style="width: 600px; height: 41px;">
<pre><strong>Input:</strong> head = [0,3,1,0,4,5,2,0]
<strong>Output:</strong> [4,11]
<strong>Explanation:</strong> 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/02/ex2-1.png" style="width: 600px; height: 41px;">
<pre><strong>Input:</strong> head = [0,1,0,3,0,2,2,0]
<strong>Output:</strong> [1,3,4]
<strong>Explanation:</strong> 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[3, 2 * 10<sup>5</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
	<li>There are <strong>no</strong> two consecutive nodes with <code>Node.val == 0</code>.</li>
	<li>The <strong>beginning</strong> and <strong>end</strong> of the linked list have <code>Node.val == 0</code>.</li>
</ul>


**Similar Questions**:
* [Linked List Components (Medium)](https://leetcode.com/problems/linked-list-components/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/merge-nodes-in-between-zeros/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy, *tail = &dummy;
        while (head) {
            if (head->val == 0) head = head->next; // skip leading `0`
            if (!head) break;
            int sum = 0;
            while (head->val != 0) { // sum numbers before the next `0`
                sum += head->val;
                head = head->next;
            }
            tail->next = new ListNode(sum); // append `sum`
            tail = tail->next;
        }
        return dummy.next;
    }
};
```

## Solution 2.

If we are asked to do it in-place.

```cpp
// OJ: https://leetcode.com/problems/merge-nodes-in-between-zeros/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) as it's done in-place
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy, *tail = &dummy;
        while (head) {
            if (head->val == 0) head = head->next;
            if (!head) break;
            auto node = head;
            head = head->next;
            while (head->val != 0) {
                node->val += head->val;
                head = head->next;
            }
            tail->next = node;
            tail = tail->next;
            node->next = nullptr;
        }
        return dummy.next;
    }
};
```

If you are asked to add the code to free node:

```cpp
// OJ: https://leetcode.com/problems/merge-nodes-in-between-zeros/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) as it's done in-place
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy, *tail = &dummy;
        while (head) {
            if (head->val == 0) {
                auto p = head;
                head = head->next;
                delete p;
            }
            if (!head) break;
            auto node = head;
            head = head->next;
            while (head->val != 0) {
                node->val += head->val;
                auto p = head;
                head = head->next;
                delete p;
            }
            tail->next = node;
            tail = tail->next;
            node->next = nullptr;
        }
        return dummy.next;
    }
};
```

## Discuss

https://leetcode.com/problems/merge-nodes-in-between-zeros/discuss/1784739/