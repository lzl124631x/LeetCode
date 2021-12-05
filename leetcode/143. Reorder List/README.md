# [143. Reorder List (Medium)](https://leetcode.com/problems/reorder-list/)

<p>You are given the head of a singly linked-list. The list can be represented as:</p>

<pre>L<sub>0</sub> → L<sub>1</sub> → … → L<sub>n - 1</sub> → L<sub>n</sub>
</pre>

<p><em>Reorder the list to be on the following form:</em></p>

<pre>L<sub>0</sub> → L<sub>n</sub> → L<sub>1</sub> → L<sub>n - 1</sub> → L<sub>2</sub> → L<sub>n - 2</sub> → …
</pre>

<p>You may not modify the values in the list's nodes. Only nodes themselves may be changed.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg" style="width: 422px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4]
<strong>Output:</strong> [1,4,2,3]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [1,5,2,4,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 5 * 10<sup>4</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Stack](https://leetcode.com/tag/stack/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Delete the Middle Node of a Linked List (Medium)](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reorder-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int getLength(ListNode *head) {
        int ans = 0;
        for (; head; head = head->next) ++ans;
        return ans;
    }
    ListNode *splitList(ListNode *head) {
        int len = (getLength(head) - 1) / 2;
        while (len--) head = head->next;
        auto ans = head->next;
        head->next = nullptr;
        return ans;
    }
    ListNode *reverseList(ListNode *head) {
        ListNode dummy;
        while (head) {
            auto node = head;
            head = head->next;
            node->next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }
    void interleave(ListNode *first, ListNode *second) {
        while (second) {
            auto node = second;
            second = second->next;
            node->next = first->next;
            first->next = node;
            first = node->next;
        }
    }
public:
    void reorderList(ListNode* head) {
        auto second = splitList(head);
        second = reverseList(second);
        interleave(head, second);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/reorder-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    ListNode *splitList(ListNode *head) {
        auto fast = head, slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto ans = slow->next;
        slow->next = nullptr;
        return ans;
    }
    ListNode *reverseList(ListNode *head) {
        ListNode dummy;
        while (head) {
            auto node = head;
            head = head->next;
            node->next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }
    void interleave(ListNode *first, ListNode *second) {
        ListNode dummy, *tail = &dummy;
        while (first && second) {
            auto node = first;
            first = first->next;
            tail->next = node;
            tail = node;
            node = second;
            second = second->next;
            tail->next = node;
            tail = node;
        }
        tail->next = first;
    }
public:
    void reorderList(ListNode* head) {
        auto second = splitList(head);
        second = reverseList(second);
        interleave(head, second);
    }
};
```