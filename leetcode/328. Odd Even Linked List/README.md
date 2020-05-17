# [328. Odd Even Linked List (Medium)](https://leetcode.com/problems/odd-even-linked-list/)

<p>Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.</p>

<p>You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.</p>

<p><b>Example 1:</b></p>

<pre><strong>Input: </strong><code>1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL</code>
<strong>Output: </strong><code>1-&gt;3-&gt;5-&gt;2-&gt;4-&gt;NULL</code>
</pre>

<p><b>Example 2:</b></p>

<pre><strong>Input: </strong>2<code>-&gt;1-&gt;3-&gt;5-&gt;6-&gt;4-&gt;7-&gt;NULL</code>
<strong>Output: </strong><code>2-&gt;3-&gt;6-&gt;7-&gt;1-&gt;5-&gt;4-&gt;NULL</code>
</pre>

<p><b>Note:</b></p>

<ul>
	<li>The relative order inside both the even and odd groups should remain as it was in the input.</li>
	<li>The first node is considered odd, the second node even and so on ...</li>
</ul>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Split Linked List in Parts (Medium)](https://leetcode.com/problems/split-linked-list-in-parts/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/odd-even-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode oddHead, *oddTail = &oddHead, evenHead, *evenTail = &evenHead;
        bool odd = true;
        while (head) {
            if (odd) {
                oddTail->next = head;
                oddTail = head;
            } else {
                evenTail->next = head;
                evenTail = head;
            }
            head = head->next;
            odd = !odd;
        }
        oddTail->next = evenHead.next;
        evenTail->next = NULL;
        return oddHead.next;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/odd-even-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd = head, *even = head->next, *evenHead = head->next;
        while (even && even->next) {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
```