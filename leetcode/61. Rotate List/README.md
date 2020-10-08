# [61. Rotate List (Medium)](https://leetcode.com/problems/rotate-list/)

<p>Given a linked&nbsp;list, rotate the list to the right by <em>k</em> places, where <em>k</em> is non-negative.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL, k = 2
<strong>Output:</strong> 4-&gt;5-&gt;1-&gt;2-&gt;3-&gt;NULL
<strong>Explanation:</strong>
rotate 1 steps to the right: 5-&gt;1-&gt;2-&gt;3-&gt;4-&gt;NULL
rotate 2 steps to the right: 4-&gt;5-&gt;1-&gt;2-&gt;3-&gt;NULL
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 0-&gt;1-&gt;2-&gt;NULL, k = 4
<strong>Output:</strong> <code>2-&gt;0-&gt;1-&gt;NULL</code>
<strong>Explanation:</strong>
rotate 1 steps to the right: 2-&gt;0-&gt;1-&gt;NULL
rotate 2 steps to the right: 1-&gt;2-&gt;0-&gt;NULL
rotate 3 steps to the right:&nbsp;<code>0-&gt;1-&gt;2-&gt;NULL</code>
rotate 4 steps to the right:&nbsp;<code>2-&gt;0-&gt;1-&gt;NULL</code></pre>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Rotate Array (Easy)](https://leetcode.com/problems/rotate-array/)
* [Split Linked List in Parts (Medium)](https://leetcode.com/problems/split-linked-list-in-parts/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/rotate-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int getLength(ListNode *head) {
        int len = 0;
        for (; head; head = head->next, ++len);
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int len = getLength(head);
        k %= len;
        if (k == 0) return head;
        auto p = head, q = head;
        while (k--) q = q->next;
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        auto h = p->next;
        q->next = head;
        p->next = NULL;
        return h;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/rotate-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int len = 1;
        auto p = head;
        for (; p->next; ++len, p = p->next);
        p->next = head;
        k = len - k % len;
        while (k--) p = p->next;
        head = p->next;
        p->next = NULL;
        return head;
    }
};
```