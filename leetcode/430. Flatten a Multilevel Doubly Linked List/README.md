# [430. Flatten a Multilevel Doubly Linked List (Medium)](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)

<p>You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.</p>

<p>Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
<strong>Output:</strong> [1,2,3,7,8,11,12,9,10,4,5,6]
<strong>Explanation:
</strong>
The multilevel linked list in the input is as follows:

<img src="https://assets.leetcode.com/uploads/2018/10/12/multilevellinkedlist.png" style="width: 640px;">

After flattening the multilevel linked list it becomes:

<img src="https://assets.leetcode.com/uploads/2018/10/12/multilevellinkedlistflattened.png" style="width: 1100px;">
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> head = [1,2,null,3]
<strong>Output:</strong> [1,3,2]
<strong>Explanation:

</strong>The input multilevel linked list is as follows:

  1---2---NULL
  |
  3---NULL
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>

<p><strong>How&nbsp;multilevel linked list is represented in test case:</strong></p>

<p>We use the&nbsp;multilevel linked list from <strong>Example 1</strong> above:</p>

<pre> 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL</pre>

<p>The serialization of each level is as follows:</p>

<pre>[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
</pre>

<p>To serialize all levels together we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:</p>

<pre>[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
</pre>

<p>Merging the serialization of each level and removing trailing nulls we obtain:</p>

<pre>[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>Number of Nodes will not exceed 1000.</li>
	<li><code>1 &lt;= Node.val &lt;= 10^5</code></li>
</ul>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Flatten Binary Tree to Linked List (Medium)](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

## Solution 1. Recursive

```cpp
// OJ: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return NULL;
        Node dummy, *tail = &dummy;
        while (head) {
            auto node = head;
            head = head->next;
            tail->next = node;
            node->prev = tail;
            tail = node;
            if (node->child) {
                auto next = flatten(node->child);
                tail->next = next;
                next->prev = tail;
                while (tail->next) tail = tail->next;
            }
            node->child = NULL;
        }
        dummy.next->prev = NULL;
        return dummy.next;
    }
};
```

## Solution 2. Stack

```cpp
// OJ: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return NULL;
        Node dummy, *tail = &dummy;
        stack<Node*> s;
        s.push(head);
        while (s.size()) {
            auto node = s.top(), child = node->child;
            tail->next = node;
            node->prev = tail;
            tail = node;
            node->child = NULL;
            if (node->next) s.top() = node->next;
            else s.pop();
            if (child) s.push(child);
        }
        dummy.next->prev = NULL;
        return dummy.next;
    }
};
```

## Solution 3. Recursive

Return a pair of pointers to first node and last node so that we don't need to traversel the flattened child again during the recursion.

```cpp
// OJ: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H) where H is the max depth of the child hierarchy.
class Solution {
    pair<Node*, Node*> dfs(Node* head) {
        if (!head) return {NULL, NULL};
        pair<Node*, Node*> p = {head, NULL}; // first node, last node.
        while (head) {
            auto next = head->next;
            auto last = head;
            if (head->child) {
                auto q = dfs(head->child);
                head->next = q.first;
                q.first->prev = head;
                if (next) {
                    q.second->next = next;
                    next->prev = q.second;
                } else last = q.second;
                head->child = NULL;
            }
            if (!next) p.second = last;
            head = next;
        }
        return p;
    }
public:
    Node* flatten(Node* head) {
        return dfs(head).first;
    }
};
```

## Solution 4.

```cpp
// OJ: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    Node* flatten(Node* head) {
        for (auto p = head; p; p = p->next) {
            if (!p->child) continue;
            auto next = p->next, q = p->child;
            p->next = q;
            q->prev = p;
            while (q->next) q = q->next;
            q->next = next;
            if (next) next->prev = q;
            p->child = NULL;
        }
        return head;
    }
};
```
