# [1171. Remove Zero Sum Consecutive Nodes from Linked List (Medium)](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)

<p>Given the <code>head</code> of a linked list, we repeatedly delete consecutive sequences of nodes that sum to <code>0</code> until there are no such sequences.</p>

<p>After doing so, return the head of the final linked list.&nbsp; You may return any such answer.</p>

<p>&nbsp;</p>
<p>(Note that in the examples below, all sequences are serializations of <code>ListNode</code> objects.)</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> head = [1,2,-3,3,1]
<strong>Output:</strong> [3,1]
<strong>Note:</strong> The answer [1,2,1] would also be accepted.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> head = [1,2,3,-3,4]
<strong>Output:</strong> [1,2,4]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = [1,2,3,-3,-2]
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The given linked list will contain between <code>1</code> and <code>1000</code> nodes.</li>
	<li>Each node in the linked list has <code>-1000 &lt;= node.val &lt;= 1000</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Delete N Nodes After M Nodes of a Linked List (Easy)](https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        unordered_map<int, ListNode*> m{{0, &dummy}};
        auto node = head;
        int sum = 0;
        while (node) {
            sum += node->val;
            if (m.count(sum)) {
                int s = sum;
                for (auto p = m[sum]->next; p != node; p = p->next) {
                    s += p->val;
                    m.erase(s);
                }
                m[sum]->next = node->next;
            if (m.count(sum)) {
            } else {
                m[sum] = node;
            }
            node = node->next;
        }
        return dummy.next;
    }
};
```