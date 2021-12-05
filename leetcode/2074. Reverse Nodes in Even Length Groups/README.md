# [2074. Reverse Nodes in Even Length Groups (Medium)](https://leetcode.com/problems/reverse-nodes-in-even-length-groups/)

<p>You are given the <code>head</code> of a linked list.</p>

<p>The nodes in the linked list are <strong>sequentially</strong> assigned to <strong>non-empty</strong> groups whose lengths form the sequence of the natural numbers (<code>1, 2, 3, 4, ...</code>). The <strong>length</strong> of a group is the number of nodes assigned to it. In other words,</p>

<ul>
	<li>The <code>1<sup>st</sup></code> node is assigned to the first group.</li>
	<li>The <code>2<sup>nd</sup></code> and the <code>3<sup>rd</sup></code> nodes are assigned to the second group.</li>
	<li>The <code>4<sup>th</sup></code>, <code>5<sup>th</sup></code>, and <code>6<sup>th</sup></code> nodes are assigned to the third group, and so on.</li>
</ul>

<p>Note that the length of the last group may be less than or equal to <code>1 + the length of the second to last group</code>.</p>

<p><strong>Reverse</strong> the nodes in each group with an <strong>even</strong> length, and return <em>the</em> <code>head</code> <em>of the modified linked list</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/25/eg1.png" style="width: 699px; height: 124px;">
<pre><strong>Input:</strong> head = [5,2,6,3,9,1,7,3,8,4]
<strong>Output:</strong> [5,6,2,3,9,1,4,8,3,7]
<strong>Explanation:</strong>
- The length of the first group is 1, which is odd, hence no reversal occurrs.
- The length of the second group is 2, which is even, hence the nodes are reversed.
- The length of the third group is 3, which is odd, hence no reversal occurrs.
- The length of the last group is 4, which is even, hence the nodes are reversed.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/25/eg2.png" style="width: 284px; height: 114px;">
<pre><strong>Input:</strong> head = [1,1,0,6]
<strong>Output:</strong> [1,0,1,6]
<strong>Explanation:</strong>
- The length of the first group is 1. No reversal occurrs.
- The length of the second group is 2. The nodes are reversed.
- The length of the last group is 1. No reversal occurrs.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/28/eg3.png" style="width: 139px; height: 114px;">
<pre><strong>Input:</strong> head = [2,1]
<strong>Output:</strong> [2,1]
<strong>Explanation:</strong>
- The length of the first group is 1. No reversal occurrs.
- The length of the last group is 1. No reversal occurrs.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> head = [8]
<strong>Output:</strong> [8]
<strong>Explanation:</strong> There is only one group whose length is 1. No reversal occurrs.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Reverse Nodes in k-Group (Hard)](https://leetcode.com/problems/reverse-nodes-in-k-group/)
* [Reverse Linked List (Easy)](https://leetcode.com/problems/reverse-linked-list/)

## Solution 1. Two Pass

```cpp
// OJ: https://leetcode.com/problems/reverse-nodes-in-even-length-groups/
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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy, *tail = &dummy;
        for (int i = 1, total = getLength(head); head; ++i) {
            int len = min(total, i); // the length of the current section
            ListNode *newTail = NULL; // The new tail if we need to reverse the current section
            for (int j = 0; j < len && head; ++j) {
                auto p = head;
                head = head->next;
                if (len % 2) { // direct append
                    tail->next = p;
                    tail = p;
                } else { // append in reverse order
                    if (newTail == NULL) newTail = p;
                    p->next = tail->next; 
                    tail->next = p;
                }
            }
            if (newTail) tail = newTail;
            total -= len;
        }
        tail->next = NULL;
        return dummy.next;
    }
};
```

## Discuss

https://leetcode.com/problems/reverse-nodes-in-even-length-groups/discuss/1576917/C%2B%2B-Two-Pass