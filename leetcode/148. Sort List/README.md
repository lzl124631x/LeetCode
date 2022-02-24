# [148. Sort List (Medium)](https://leetcode.com/problems/sort-list/)

<p>Given the <code>head</code> of a linked list, return <em>the list after sorting it in <strong>ascending order</strong></em>.</p>

<p><strong>Follow up:</strong> Can you sort the linked list in <code>O(n logn)</code> time and <code>O(1)</code>&nbsp;memory (i.e. constant space)?</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg" style="width: 450px; height: 194px;">
<pre><strong>Input:</strong> head = [4,2,1,3]
<strong>Output:</strong> [1,2,3,4]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg" style="width: 550px; height: 184px;">
<pre><strong>Input:</strong> head = [-1,5,3,4,0]
<strong>Output:</strong> [-1,0,3,4,5]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 5 * 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Adobe](https://leetcode.com/company/adobe), [Yahoo](https://leetcode.com/company/yahoo), [Bloomberg](https://leetcode.com/company/bloomberg), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Merge Two Sorted Lists (Easy)](https://leetcode.com/problems/merge-two-sorted-lists/)
* [Sort Colors (Medium)](https://leetcode.com/problems/sort-colors/)
* [Insertion Sort List (Medium)](https://leetcode.com/problems/insertion-sort-list/)

## Solution 1. Merge Sort

```cpp
// OJ: https://leetcode.com/problems/sort-list/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(logN)
class Solution {
    ListNode* splitList(ListNode *head) {
        ListNode dummy, *p = &dummy, *q = &dummy;
        dummy.next = head;
        while (q && q->next) {
            q = q->next->next;
            p = p->next;
        }
        auto next = p->next;
        p->next = NULL;
        return next;
    }
    ListNode *mergeList(ListNode *a, ListNode *b) {
        ListNode head, *tail = &head;
        while (a && b) {
            ListNode *node;
            if (a->val <= b->val) {
                node = a;
                a = a->next;
            } else {
                node = b;
                b = b->next;
            }
            tail->next = node;
            tail = node;
        }
        if (a) tail->next = a;
        if (b) tail->next = b;
        return head.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto b = splitList(head);
        return mergeList(sortList(head), sortList(b));
    }
};
```

## Solution 2. Quick Sort

```cpp
// OJ: https://leetcode.com/problems/sort-list/
// Author: github.com/lzl124631x
// Time: O(NlogN) on average, O(N^2) in the worst case
// Space: O(logN) on averge, O(N) in the worst case
class Solution {
private:
    void quickSort(ListNode *begin, ListNode *end = NULL) {
        if (begin == end || begin->next == end) return;
        auto p = partition(begin, end);
        quickSort(begin, p.first);
        quickSort(p.second, end);
    }
    pair<ListNode*, ListNode*> partition(ListNode *begin, ListNode *end) {
        int pivot = begin->val;
        ListNode *eqHead = begin, *eqTail = begin, *p = begin->next;
        while (p != end) {
            if (p->val <= pivot) {
                if (p->val < pivot) {
                    swap(eqHead->val, p->val);
                    eqHead = eqHead->next;
                }
                swap(p->val, eqTail->next->val);
                eqTail = eqTail->next;
            }
            p = p->next;
        }
        return {eqHead, eqTail->next};
    }
public:
    ListNode* sortList(ListNode* head) {
        quickSort(head);
        return head;
    }
};
```

## Solution 3. Bottom-up Merge Sort

```cpp
// OJ: https://leetcode.com/problems/sort-list/solution/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
    pair<ListNode*, ListNode*> mergeList(ListNode *a, ListNode *b) {
        ListNode head, *tail = &head;
        while (a || b) {
            ListNode *node;
            if (!b || (a && a->val <= b->val)) {
                node = a;
                a = a->next;
            } else {
                node = b;
                b = b->next;
            }
            tail->next = node;
            tail = node;
        }
        return {head.next, tail};
    }
    int getLength(ListNode *head) {
        int ans = 0;
        for (; head; head = head->next, ++ans);
        return ans;
    }
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        int length = getLength(head);
        for (int len = 1; len < length; len *= 2) {
            auto p = dummy.next, prev = &dummy;
            while (p) {
                auto a = p;
                for (int i = 1; i < len && p->next; ++i) p = p->next;
                auto b = p->next;
                p->next = NULL;
                if (b == NULL) break;
                p = b;
                for (int i = 1; i < len && p->next; ++i) p = p->next;
                auto next = p->next;
                p->next = NULL;
                auto [h, t] = mergeList(a, b);
                prev->next = h;
                t->next = next;
                p = next;
                prev = t;
            }
        }
        return dummy.next;
    }
};
```