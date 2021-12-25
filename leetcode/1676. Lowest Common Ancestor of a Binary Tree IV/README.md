# [1676. Lowest Common Ancestor of a Binary Tree IV (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/)

<p>Given the <code>root</code> of a binary tree and an array of <code>TreeNode</code> objects <code>nodes</code>, return <em>the lowest common ancestor (LCA) of <strong>all the nodes</strong> in </em><code>nodes</code>. All the nodes will exist in the tree, and all values of the tree's nodes are <strong>unique</strong>.</p>

<p>Extending the <strong><a href="https://en.wikipedia.org/wiki/Lowest_common_ancestor" target="_blank">definition of LCA on Wikipedia</a></strong>: "The lowest common ancestor of <code>n</code> nodes <code>p<sub>1</sub></code>, <code>p<sub>2</sub></code>, ..., <code>p<sub>n</sub></code> in a binary tree <code>T</code> is the lowest node that has every <code>p<sub>i</sub></code> as a <strong>descendant</strong> (where we allow <b>a node to be a descendant of itself</b>) for every valid <code>i</code>". A <strong>descendant</strong> of a node <code>x</code> is a node <code>y</code> that is on the path from node <code>x</code> to some leaf node.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [4,7]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The lowest common ancestor of nodes 4 and 7 is node 2.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The lowest common ancestor of a single node is the node itself.

</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [7,6,2,4]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The lowest common ancestor of the nodes 7, 6, 2, and 4 is node 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li>All <code>Node.val</code> are <strong>unique</strong>.</li>
	<li>All <code>nodes[i]</code> will exist in the tree.</li>
	<li>All <code>nodes[i]</code> are distinct.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Lowest Common Ancestor of a Binary Search Tree (Easy)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
* [Lowest Common Ancestor of a Binary Tree (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
* [Lowest Common Ancestor of Deepest Leaves (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/)
* [Lowest Common Ancestor of a Binary Tree II (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/)
* [Lowest Common Ancestor of a Binary Tree III (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/)
* [Lowest Common Ancestor of a Binary Tree IV (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/)

## Solution 1. Post-order Traversal

```cpp
// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/
// Author: github.com/lzl124631x
// Time: O(N + T) where `N` is the number of nodes in the tree, `T` is the size of `nodes`, and `H` is the height of the tree.
// Space: O(H + T)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> s(begin(nodes), end(nodes));
        function<TreeNode*(TreeNode*)> dfs = [&](TreeNode *node) -> TreeNode*{
            if (!node) return nullptr;
            if (s.count(node)) return node;
            auto left = dfs(node->left), right = dfs(node->right);
            return !left ? right : (!right ? left : node);
        };
        return dfs(root);
    }
};
```