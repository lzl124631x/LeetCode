# [445. Add Two Numbers II (Medium)](https://leetcode.com/problems/add-two-numbers-ii/)

<p>You are given two <b>non-empty</b> linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.</p>

<p>You may assume the two numbers do not contain any leading zero, except the number 0 itself.</p>

<p><b>Follow up:</b><br>
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
</p>

<p>
<b>Example:</b>
</p><pre><b>Input:</b> (7 -&gt; 2 -&gt; 4 -&gt; 3) + (5 -&gt; 6 -&gt; 4)
<b>Output:</b> 7 -&gt; 8 -&gt; 0 -&gt; 7
</pre>
<p></p>

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Add Two Numbers (Medium)](https://leetcode.com/problems/add-two-numbers/)
* [Add Two Polynomials Represented as Linked Lists (Medium)](https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/)

## Solution 1. Reverse + Add + Reverse

```cpp
// OJ: https://leetcode.com/problems/add-two-numbers-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    ListNode *reverse(ListNode *h) {
        ListNode dummy;
        while (h) {
            auto p = h;
            h = h->next;
            p->next = dummy.next;
            dummy.next = p;
        }
        return dummy.next;
    }
    ListNode* add(ListNode* a, ListNode* b) {
        int carry = 0;
        ListNode dummy, *tail = &dummy;
        while (a || b || carry) {
            if (a) {
                carry += a->val;
                a = a->next;
            }
            if (b) {
                carry += b->val;
                b = b->next;
            }
            tail->next = new ListNode(carry % 10);
            tail = tail->next;
            carry /= 10;
        }
        return dummy.next;
    }
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        a = reverse(a);
        b = reverse(b);
        return reverse(add(a, b));
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/add-two-numbers-ii/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(1)
class Solution {
    int getLength(ListNode *head) {
        int ans = 0;
        for (; head; head = head->next) ++ans;
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
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        int la = getLength(a), lb = getLength(b);
        if (la < lb) swap(a, b), swap(la, lb);
        int diff = la - lb;
        ListNode head;
        while (a) {
            int carry = a->val;
            a = a->next;
            if (diff) --diff;
            else {
                carry += b->val;
                b = b->next;
            }
            auto node = new ListNode(carry % 10);
            node->next = head.next;
            head.next = node;
            carry /= 10;
            while (carry && node->next) {
                carry += node->next->val;
                node->next->val = carry % 10;
                carry /= 10;
                node = node->next;
            }
            if (carry) node->next = new ListNode(carry);
        }
        return reverseList(head.next);
    }
};
```