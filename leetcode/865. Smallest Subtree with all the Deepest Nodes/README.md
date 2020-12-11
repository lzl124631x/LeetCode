# [865. Smallest Subtree with all the Deepest Nodes (Medium)](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/)

<p>Given the <code>root</code> of a binary tree, the depth of each node is <strong>the shortest distance to the root</strong>.</p>

<p>Return <em>the smallest subtree</em> such that it contains <strong>all the deepest nodes</strong> in the original tree.</p>

<p>A node is called <strong>the&nbsp;deepest</strong> if it has the largest depth possible among&nbsp;any node in the entire tree.</p>

<p>The <strong>subtree</strong> of a node is tree consisting of that node, plus the set of all descendants of that node.</p>

<p><strong>Note:</strong> This question is the same as 1123: <a href="https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/" target="_blank">https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/</a></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/01/sketch1.png" style="width: 600px; height: 510px;">
<pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4]
<strong>Output:</strong> [2,7,4]
<strong>Explanation:</strong> We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [1]
<strong>Explanation:</strong> The root is the deepest node in the tree.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [0,1,3,null,2]
<strong>Output:</strong> [2]
<strong>Explanation:</strong> The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree will be in the range <code>[1, 500]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 500</code></li>
	<li>The values of the nodes in the tree&nbsp;are <strong>unique</strong>.</li>
</ul>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Recursion](https://leetcode.com/tag/recursion/)

## Solution 1.

```cpp
## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int maxDepth = -1, target = 0, cnt = 0;
    void count(TreeNode *root, int d) {
        if (!root) return;
        if (d > maxDepth) {
            target = 1;
            maxDepth = d;
        } else if (d == maxDepth) ++target;
        count(root->left, d + 1);
        count(root->right, d + 1);
    }
    TreeNode *find(TreeNode *root, int d) {
        if (!root) return NULL;
        int before = cnt;
        auto left = find(root->left, d + 1);
        if (left) return left;
        auto right = find(root->right, d + 1);
        if (right) return right;
        if (d == maxDepth) ++cnt;
        return before == 0 && cnt == target ? root : NULL;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        count(root, 0);
        return find(root, 0);
    }
};
```

## Solution 2.

The lowest ancester is the highest node whose left and right subtrees have the same height.

```cpp
// OJ: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    pair<TreeNode*, int> dfs(TreeNode *root, int d = 0) { // latest node which has equal depth in left and right sub-trees; the corresponding height
        if (!root) return {NULL, 0};
        const auto &[left, ld] = dfs(root->left, d + 1);
        const auto &[right, rd] = dfs(root->right, d + 1);
        if (ld > rd) return {left, ld + 1};
        else if (ld < rd) return{right, rd + 1};
        return {root, ld + 1};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};
```