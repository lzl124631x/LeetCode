# [510. Inorder Successor in BST II (Medium)](https://leetcode.com/problems/inorder-successor-in-bst-ii/)

<p>Given a <code>node</code> in a binary search tree, return <em>the in-order successor of that node in the BST</em>. If that node has no in-order successor, return <code>null</code>.</p>

<p>The successor of a <code>node</code> is the node with the smallest key greater than <code>node.val</code>.</p>

<p>You will have direct access to the node but not to the root of the tree. Each node will have a reference to its parent node. Below is the definition for <code>Node</code>:</p>

<pre>class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
</pre>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/01/23/285_example_1.PNG" style="width: 122px; height: 117px;">
<pre><strong>Input:</strong> tree = [2,1,3], node = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> 1's in-order successor node is 2. Note that both the node and the return value is of Node type.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/01/23/285_example_2.PNG" style="width: 246px; height: 229px;">
<pre><strong>Input:</strong> tree = [5,3,6,2,4,null,null,1], node = 6
<strong>Output:</strong> null
<strong>Explanation:</strong> There is no in-order successor of the current node, so the answer is null.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>All Nodes will have unique values.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you solve it without looking up any of the node's values?</p>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Inorder Successor in BST (Medium)](https://leetcode.com/problems/inorder-successor-in-bst/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/inorder-successor-in-bst-ii/
// Author: github.com/lzl124631x
// Time: O(H)
// Space: O(1)
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            Node *n = nullptr;
            for (auto p = node->right; p; p = p->left) n = p;
            return n;
        }
        auto p = node->parent;
        while (p && p->val < node->val) p = p->parent;
        return p;
    }
};
```