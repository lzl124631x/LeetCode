# [206. Reverse Linked List (Easy)](https://leetcode.com/problems/reverse-linked-list/)

<p>Given the <code>head</code> of a singly linked list, reverse the list, and return <em>the reversed list</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [5,4,3,2,1]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg" style="width: 182px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2]
<strong>Output:</strong> [2,1]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is the range <code>[0, 5000]</code>.</li>
	<li><code>-5000 &lt;= Node.val &lt;= 5000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> A linked list can be reversed either iteratively or recursively. Could you implement both?</p>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Bloomberg](https://leetcode.com/company/bloomberg), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple), [Nvidia](https://leetcode.com/company/nvidia), [Google](https://leetcode.com/company/google), [Yandex](https://leetcode.com/company/yandex), [Adobe](https://leetcode.com/company/adobe), [eBay](https://leetcode.com/company/ebay), [IBM](https://leetcode.com/company/ibm)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Reverse Linked List II (Medium)](https://leetcode.com/problems/reverse-linked-list-ii/)
* [Binary Tree Upside Down (Medium)](https://leetcode.com/problems/binary-tree-upside-down/)
* [Palindrome Linked List (Easy)](https://leetcode.com/problems/palindrome-linked-list/)
* [Reverse Nodes in Even Length Groups (Medium)](https://leetcode.com/problems/reverse-nodes-in-even-length-groups/)

## Solution 1. Iterative

```cpp
// OJ: https://leetcode.com/problems/reverse-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode h;
        while (head) {
            auto p = head;
            head = head->next;
            p->next = h.next;
            h.next = p;
        }
        return h.next;
    }
};
```

## Solution 2. Recursive

```cpp
// OJ: https://leetcode.com/problems/reverse-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    array<ListNode*, 2> reverse(ListNode *head) {
        if (!head->next) return {head, head};
        auto [h, t] = reverse(head->next);
        t->next = head;
        head->next = NULL;
        return {h, head};
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        return reverse(head)[0];
    }
};
```