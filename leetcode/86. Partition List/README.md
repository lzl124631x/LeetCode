# [86. Partition List (Medium)](https://leetcode.com/problems/partition-list/)

<p>Given a linked list and a value <em>x</em>, partition it such that all nodes less than <em>x</em> come before nodes greater than or equal to <em>x</em>.</p>

<p>You should preserve the original relative order of the nodes in each of the two partitions.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> head = 1-&gt;4-&gt;3-&gt;2-&gt;5-&gt;2, <em>x</em> = 3
<strong>Output:</strong> 1-&gt;2-&gt;2-&gt;4-&gt;3-&gt;5
</pre>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/partition-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode ltHead(0), *ltTail = &ltHead, geHead(0), *geTail = &geHead;
        while (head) {
            auto node = head;
            head = head->next;
            if (node->val < x) {
                ltTail->next = node;
                ltTail = node;
            } else {
                geTail->next = node;
                geTail = node;
            }
        }
        ltTail->next = geHead.next;
        geTail->next = NULL;
        return ltHead.next;
    }
};
```