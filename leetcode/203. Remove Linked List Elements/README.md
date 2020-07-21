# [203. Remove Linked List Elements (Easy)](https://leetcode.com/problems/remove-linked-list-elements/)

<p>Remove all elements from a linked list of integers that have value <b><i>val</i></b>.</p>

<p><b>Example:</b></p>

<pre><b>Input:</b>  1-&gt;2-&gt;6-&gt;3-&gt;4-&gt;5-&gt;6, <em><b>val</b></em> = 6
<b>Output:</b> 1-&gt;2-&gt;3-&gt;4-&gt;5
</pre>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

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