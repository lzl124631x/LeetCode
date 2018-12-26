# [143. Reorder List (Medium)](https://leetcode.com/problems/reorder-list/)

<p>Given a singly linked list <em>L</em>: <em>L</em><sub>0</sub>→<em>L</em><sub>1</sub>→…→<em>L</em><sub><em>n</em>-1</sub>→<em>L</em><sub>n</sub>,<br>
reorder it to: <em>L</em><sub>0</sub>→<em>L</em><sub><em>n</em></sub>→<em>L</em><sub>1</sub>→<em>L</em><sub><em>n</em>-1</sub>→<em>L</em><sub>2</sub>→<em>L</em><sub><em>n</em>-2</sub>→…</p>

<p>You may <strong>not</strong> modify the values in the list's nodes, only nodes itself may be changed.</p>

<p><strong>Example 1:</strong></p>

<pre>Given 1-&gt;2-&gt;3-&gt;4, reorder it to 1-&gt;4-&gt;2-&gt;3.</pre>

<p><strong>Example 2:</strong></p>

<pre>Given 1-&gt;2-&gt;3-&gt;4-&gt;5, reorder it to 1-&gt;5-&gt;2-&gt;4-&gt;3.
</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reorder-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    ListNode *reverse(ListNode* head) {
        ListNode dummy(0);
        while (head) {
            ListNode *node = head;
            head = head->next;
            node->next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }
    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        int len = (getLength(head) - 1) / 2;
        ListNode *p = head, *q;
        while (len--) p = p->next;
        q = p->next;
        p->next = NULL;
        q = reverse(q);
        p = head;
        while (q) {
            ListNode *node = q;
            q = q->next;
            node->next = p->next;
            p->next = node;
            p = node->next;
        }
    }
};
```

## Solution 2

```cpp
// OJ: https://leetcode.com/problems/reorder-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    ListNode *reverseList(ListNode *head) {
        ListNode newHead(0);
        while (head) {
            ListNode *p = head;
            head = head->next;
            p->next = newHead.next;
            newHead.next = p;
        }
        return newHead.next;
    }
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode *fast = head, *slow = head, *rightHead;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        rightHead = slow->next;
        slow->next = NULL;
        rightHead = reverseList(rightHead);
        while (rightHead) {
            ListNode *p = rightHead;
            rightHead = rightHead->next;
            p->next = head->next;
            head->next = p;
            head = p->next;
        }
    }
};
```