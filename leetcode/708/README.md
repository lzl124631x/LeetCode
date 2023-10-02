# [708. Insert into a Sorted Circular Linked List (Medium)](https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/)

<p>Given a Circular Linked List node, which is sorted in ascending order, write a function to insert a value <code>insertVal</code> into the list such that it remains a sorted circular list. The given node can be a reference to any single node in the list and may not necessarily be the smallest value in the circular list.</p>

<p>If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, the circular list should remain sorted.</p>

<p>If the list is empty (i.e., the given node is <code>null</code>), you should create a new single circular list and return the reference to that single node. Otherwise, you should return the originally given node.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/01/19/example_1_before_65p.jpg" style="width: 250px; height: 149px;"><br>
&nbsp;
<pre><strong>Input:</strong> head = [3,4,1], insertVal = 2
<strong>Output:</strong> [3,4,1,2]
<strong>Explanation:</strong> In the figure above, there is a sorted circular list of three elements. You are given a reference to the node with value 3, and we need to insert 2 into the list. The new node should be inserted between node 1 and node 3. After the insertion, the list should look like this, and we should still return node 3.

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/19/example_1_after_65p.jpg" style="width: 250px; height: 149px;">

</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> head = [], insertVal = 1
<strong>Output:</strong> [1]
<strong>Explanation:</strong> The list is empty (given head is&nbsp;<code>null</code>). We create a new single circular list and return the reference to that single node.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = [1], insertVal = 0
<strong>Output:</strong> [1,0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= Number of Nodes &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>6</sup> &lt;= Node.val, insertVal &lt;= 10<sup>6</sup></code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Insertion Sort List (Medium)](https://leetcode.com/problems/insertion-sort-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(U) where U is the number of unique numbers in the list
class Solution {
public:
    Node* insert(Node* head, int val) {
        auto node = new Node(val);
        node->next = node;
        if (!head) return node;
        map<int, Node*> m;
        auto p = head;
        do {
            m[p->val] = p;
            p = p->next;
        } while (p != head);
        auto it = m.upper_bound(val);
        if (it == m.end() || it == m.begin()) {
            p = m.rbegin()->second;
        } else {
            p = prev(it)->second;
        }
        node->next = p->next;
        p->next = node;
        return head;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    Node* insert(Node* head, int val) {
        auto node = new Node(val);
        node->next = node;
        if (!head) return node;
        auto p = head;
        do {
            while (p->next != head && p->next->val == p->val) p = p->next;  // skip same values
            if ((p->val >= p->next->val && (val >= p->val || val <= p->next->val)) // If `p` is the maximum node and `val` is smaller than minimum value or greater than maximum value
               || (p->val <= p->next->val && val >= p->val && val < p->next->val)) { // If `p` is not the maximum node and `val` is intween `p->val` and `p->next->val`
                node->next = p->next; // append node after `p`
                p->next = node;
                return head;
            }
            p = p->next;
        } while (p != head);
        return NULL;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    Node* insert(Node* head, int val) {
        auto node = new Node(val);
        if (!head) {
            node->next = node;
            return node;
        }
        Node *lt = NULL, *mx = head, *h = head; // `lt` is the last node whose value is less than `val`. `mx` is the node with maximum value
        do {
            if (head->val < val && (!lt || head->val >= lt->val)) lt = head;
            if (head->val >= mx->val) mx = head;
            head = head->next;
        } while (head != h);
        if (!lt) lt = mx; // If no node has value less than `val`, `val` is the smallest value, we append it after `mx` node.
        node->next = lt->next; // append node after `lt`
        lt->next = node;
        return h;
    }
};
```