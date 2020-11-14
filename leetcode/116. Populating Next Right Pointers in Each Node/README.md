# [116. Populating Next Right Pointers in Each Node (Medium)](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)

<p>You are given a <strong>perfect binary tree</strong>&nbsp;where&nbsp;all leaves are on the same level, and every parent has two children. The binary tree has the following definition:</p>

<pre>struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
</pre>

<p>Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to <code>NULL</code>.</p>

<p>Initially, all next pointers are set to <code>NULL</code>.</p>

<p>&nbsp;</p>

<p><strong>Follow up:</strong></p>

<ul>
	<li>You may only use constant extra space.</li>
	<li>Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/02/14/116_sample.png" style="width: 640px; height: 218px;"></p>

<pre><strong>Input:</strong> root = [1,2,3,4,5,6,7]
<strong>Output:</strong> [1,#,2,3,#,4,5,6,7,#]
<strong>Explanation: </strong>Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the given tree is less than <code>4096</code>.</li>
	<li><code>-1000 &lt;= node.val &lt;= 1000</code></li>
</ul>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Populating Next Right Pointers in Each Node II (Medium)](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)
* [Binary Tree Right Side View (Medium)](https://leetcode.com/problems/binary-tree-right-side-view/)

## Solution 1. DFS

The tree is a **perfect binary tree**. We can connect the nodes layer by layer.

We assume the current layer is already connected, and we iterate through the current layer to connect the nodes in the next layer.

This assumption is true because the root layer is connected, and if we do this layer-by-layer approach, each layer must be already connected when being visited.

```cpp
// OJ: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    Node* connect(Node* root) {
        auto first = root;
        while (first && first->left) {
            for (auto node = first; node; node = node->next) {
                node->left->next = node->right;
                if (node->next) node->right->next = node->next->left;
            } 
            first = first->left;
        }
        return root;
    }
};
```