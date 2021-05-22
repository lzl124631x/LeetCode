# [1650. Lowest Common Ancestor of a Binary Tree III (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/)

<p>Given two nodes of a&nbsp;binary tree <code>p</code> and <code>q</code>, return <em>their&nbsp;lowest common ancestor (LCA)</em>.</p>

<p>Each node will have a reference to its parent node. The definition for <code>Node</code> is below:</p>

<pre>class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
</pre>

<p>According to the <strong><a href="https://en.wikipedia.org/wiki/Lowest_common_ancestor" target="_blank">definition of LCA on Wikipedia</a></strong>: "The lowest common ancestor of two nodes p and q in a tree T is the lowest node that has both p and q as descendants (where we allow <b>a node to be a descendant of itself</b>)."</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png" style="width: 200px; height: 190px;">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> The LCA of nodes 5 and 1 is 3.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png" style="width: 200px; height: 190px;">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
<strong>Output:</strong> 5
<strong>Explanation:</strong> The LCA of nodes 5 and 4 is 5 since a node can be a descendant of itself according to the LCA definition.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [1,2], p = 1, q = 2
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[2, 10<sup>5</sup>]</code>.</li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li>All <code>Node.val</code> are <strong>unique</strong>.</li>
	<li><code>p != q</code></li>
	<li><code>p</code> and <code>q</code> exist in the tree.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [LinkedIn](https://leetcode.com/company/linkedin), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple), [Amazon](https://leetcode.com/company/amazon), [Yandex](https://leetcode.com/company/yandex)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Lowest Common Ancestor of a Binary Search Tree (Easy)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
* [Lowest Common Ancestor of a Binary Tree (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
* [Lowest Common Ancestor of a Binary Tree II (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/)
* [Lowest Common Ancestor of a Binary Tree IV (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int getLength(Node *p) {
        int ans = 0;
        for (; p->parent; p = p->parent, ++ans);
        return ans;
    }
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int a = getLength(p), b = getLength(q);
        if (a < b) swap(a, b), swap(p, q);
        a -= b;
        while (a-- > 0) p = p->parent;
        while (p != q) p = p->parent, q = q->parent;
        return p;
    }
};
```