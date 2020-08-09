# [99. Recover Binary Search Tree (Hard)](https://leetcode.com/problems/recover-binary-search-tree/)

<p>Two elements of a binary search tree (BST) are swapped by mistake.</p>

<p>Recover the tree without changing its structure.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [1,3,null,null,2]

&nbsp;  1
&nbsp; /
&nbsp;3
&nbsp; \
&nbsp;  2

<strong>Output:</strong> [3,1,null,null,2]

&nbsp;  3
&nbsp; /
&nbsp;1
&nbsp; \
&nbsp;  2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [3,1,4,null,null,2]

  3
 / \
1   4
&nbsp;  /
&nbsp; 2

<strong>Output:</strong> [2,1,4,null,null,3]

  2
 / \
1   4
&nbsp;  /
 &nbsp;3
</pre>

<p><strong>Follow up:</strong></p>

<ul>
	<li>A solution using O(<em>n</em>) space is pretty straight forward.</li>
	<li>Could you devise a constant space solution?</li>
</ul>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. DFS

DFS to find the minimal incorrect node `a` and the maximum incorrect node `b`, and swap them in the end.

In DFS, we use `left` and `right` to point to the left and right bound nodes respectively.

* If `root->val` is smaller than `left->val`, `root, left` is an incorrect pair.
* If `root->val` is greater than `right->val`, `right, root` is an incorrect pair.

```cpp
// OJ: https://leetcode.com/problems/recover-binary-search-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    TreeNode *a = NULL, *b = NULL;
    void update(TreeNode *x, TreeNode *y) {
        if (!a || x->val < a->val) a = x;
        if (!b || y->val > b->val) b = y;
    }
    void dfs(TreeNode *root, TreeNode *left = NULL, TreeNode *right = NULL) {
        if (!root) return;
        if (left && left->val > root->val) update(root, left);
        if (right && right->val < root->val) update(right, root);
        dfs(root->left, left, root);
        dfs(root->right, root, right);
    }
public:
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(a->val, b->val);
    }
};
```