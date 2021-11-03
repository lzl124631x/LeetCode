# [687. Longest Univalue Path (Medium)](https://leetcode.com/problems/longest-univalue-path/)

<p>Given the <code>root</code> of a binary tree, return <em>the length of the longest path, where each node in the path has the same value</em>. This path may or may not pass through the root.</p>

<p><strong>The length of the path</strong> between two nodes is represented by the number of edges between them.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/13/ex1.jpg" style="width: 571px; height: 302px;">
<pre><strong>Input:</strong> root = [5,4,5,1,1,5]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/13/ex2.jpg" style="width: 571px; height: 302px;">
<pre><strong>Input:</strong> root = [1,4,5,4,4,5]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li>The depth of the tree will not exceed <code>1000</code>.</li>
</ul>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Binary Tree Maximum Path Sum (Hard)](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
* [Count Univalue Subtrees (Medium)](https://leetcode.com/problems/count-univalue-subtrees/)
* [Path Sum III (Medium)](https://leetcode.com/problems/path-sum-iii/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/longest-univalue-path/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    int dfs(TreeNode *root) {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        if (!root->left || root->left->val != root->val) left = 0;
        if (!root->right || root->right->val != root->val) right = 0;
        ans = max(ans, 1 + left + right);
        return 1 + max(left, right);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return max(0, ans - 1);
    }
};
```