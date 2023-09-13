# [1666. Change the Root of a Binary Tree (Medium)](https://leetcode.com/problems/change-the-root-of-a-binary-tree)

<p>Given the <code>root</code> of a binary tree and a <code>leaf</code> node, reroot the tree so that the <code>leaf</code> is the new root.</p>
<p>You can reroot the tree with the following steps for each node <code>cur</code> on the path <strong>starting from the </strong><code>leaf</code> up to the <code>root</code>​​​ <strong>excluding the root</strong>:</p>
<ol>
	<li>If <code>cur</code> has a left child, then that child becomes <code>cur</code>'s right child.</li>
	<li><code>cur</code>'s original parent becomes <code>cur</code>'s left child. Note that in this process the original parent's pointer to <code>cur</code> becomes <code>null</code>, making it have at most one child.</li>
</ol>
<p>Return <em>the new root </em><em>of the rerooted tree.</em></p>
<p><strong>Note:</strong> Ensure that your solution sets the <code>Node.parent</code> pointers correctly after rerooting or you will receive "Wrong Answer".</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/24/fliptree.png" style="width: 400px; height: 298px;">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], leaf = 7
<strong>Output:</strong> [7,2,null,5,4,3,6,null,null,null,1,null,null,0,8]
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], leaf = 0
<strong>Output:</strong> [0,1,null,3,8,5,null,null,null,6,2,null,null,7,4]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>The number of nodes in the tree is in the range <code>[2, 100]</code>.</li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li>All <code>Node.val</code> are <strong>unique</strong>.</li>
	<li><code>leaf</code> exist in the tree.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/change-the-root-of-a-binary-tree
// Author: github.com/lzl124631x
// Time: O(H)
// Space: O(1)
class Solution {
public:
    Node* flipBinaryTree(Node* root, Node * leaf) {
        Node *cur = leaf, *p = leaf->parent;
        cur->parent = nullptr;
        if (p->left == cur) p->left = nullptr;
        else p->right = nullptr;
        while (cur != root) {
            if (cur->left) {
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur->left = p;
            auto pp = p->parent;
            p->parent = cur;
            if (pp) {
                if (pp->left == p) pp->left = nullptr;
                else pp->right = nullptr;
            }
            cur = p;
            p = pp;
        }
        return leaf;
    }
};
```