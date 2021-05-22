# [426. Convert Binary Search Tree to Sorted Doubly Linked List (Medium)](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/)

<p>Convert a <strong>Binary Search Tree</strong> to a sorted <strong>Circular Doubly-Linked List</strong> in place.</p>

<p>You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.</p>

<p>We want to do the transformation <strong>in place</strong>. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/bstdlloriginalbst.png" style="width: 100%; max-width: 300px;"></p>

<pre><strong>Input:</strong> root = [4,2,5,1,3]

<img src="https://assets.leetcode.com/uploads/2018/10/12/bstdllreturndll.png" style="width: 100%; max-width: 450px;">
<strong>Output:</strong> [1,2,3,4,5]

<strong>Explanation:</strong> The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.
<img src="https://assets.leetcode.com/uploads/2018/10/12/bstdllreturnbst.png" style="width: 100%; max-width: 450px;">
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> [1,2,3]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
<strong>Explanation:</strong> Input is an empty tree. Output is also an empty Linked List.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li>All the values of the tree are <strong>unique</strong>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Expedia](https://leetcode.com/company/expedia)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Binary Tree Inorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-inorder-traversal/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        auto left = treeToDoublyList(root->left), right = treeToDoublyList(root->right);
        root->left = left ? left->left : (right ? right->left : root);
        root->right = right ? right : (left ? left : root);
        if (left) {
            left->left->right = root;
            left->left = right ? right->left : root;
        }
        if (right) {
            right->left->right = left ? left : root;
            right->left = root;
        }
        return left ? left : root;
    }
};
```