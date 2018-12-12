# [206. Reverse Linked List (Easy)](https://leetcode.com/problems/reverse-linked-list/)

<p>Reverse a singly linked list.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL
<strong>Output:</strong> 5-&gt;4-&gt;3-&gt;2-&gt;1-&gt;NULL
</pre>

<p><b>Follow up:</b></p>

<p>A linked list can be reversed either iteratively or recursively. Could you implement both?</p>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple), [Mathworks](https://leetcode.com/company/mathworks), [Bloomberg](https://leetcode.com/company/bloomberg), [Adobe](https://leetcode.com/company/adobe), [Amazon](https://leetcode.com/company/amazon), [Yandex](https://leetcode.com/company/yandex), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Google](https://leetcode.com/company/google), [Baidu](https://leetcode.com/company/baidu), [Nvidia](https://leetcode.com/company/nvidia), [Expedia](https://leetcode.com/company/expedia), [Yahoo](https://leetcode.com/company/yahoo), [Cisco](https://leetcode.com/company/cisco)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Reverse Linked List II (Medium)](https://leetcode.com/problems/reverse-linked-list-ii/)
* [Binary Tree Upside Down (Medium)](https://leetcode.com/problems/binary-tree-upside-down/)
* [Palindrome Linked List (Easy)](https://leetcode.com/problems/palindrome-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reverse-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        while (head) {
            ListNode *node = head;
            head = head->next;
            node->next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }
};
```