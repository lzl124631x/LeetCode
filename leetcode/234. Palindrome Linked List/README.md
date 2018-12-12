# [234. Palindrome Linked List (Easy)](https://leetcode.com/problems/palindrome-linked-list/)

<p>Given a singly linked list, determine if it is a palindrome.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 1-&gt;2
<strong>Output:</strong> false</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 1-&gt;2-&gt;2-&gt;1
<strong>Output:</strong> true</pre>

<p><b>Follow up:</b><br>
Could you do it in O(n) time and O(1) space?</p>


**Companies**:  
[IXL](https://leetcode.com/company/ixl), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Palindrome Number (Easy)](https://leetcode.com/problems/palindrome-number/)
* [Valid Palindrome (Easy)](https://leetcode.com/problems/valid-palindrome/)
* [Reverse Linked List (Easy)](https://leetcode.com/problems/reverse-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/palindrome-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    int getLength(ListNode *head) {
        int len = 0;
        for (; head; head = head->next, ++len);
        return len;
    }
    ListNode *reverse(ListNode *head) {
        ListNode dummy(0);
        while (head) {
            ListNode *node = head;
            head = head->next;
            node->next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        int len = (getLength(head) + 1) / 2;
        ListNode *p = head, *q;
        while (--len > 0) p = p->next;
        q = p->next;
        p->next = NULL;
        q = reverse(q);
        while (head && q) {
            if (head->val != q->val) return false;
            head = head->next;
            q = q->next;
        }
        return true;
    }
};
```