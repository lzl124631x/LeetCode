# [101. Symmetric Tree (Easy)](https://leetcode.com/problems/symmetric-tree)

<p>Given the <code>root</code> of a binary tree, <em>check whether it is a mirror of itself</em> (i.e., symmetric around its center).</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg" style="width: 354px; height: 291px;">
<pre><strong>Input:</strong> root = [1,2,2,3,4,4,3]
<strong>Output:</strong> true
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg" style="width: 308px; height: 258px;">
<pre><strong>Input:</strong> root = [1,2,2,null,3,null,3]
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 1000]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>
<p>&nbsp;</p>
<strong>Follow up:</strong>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Yandex](https://leetcode.com/company/yandex), [TikTok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/symmetric-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    bool dfs(TreeNode* A, TreeNode* B) {
        return (!A && !B) || (A && B && A->val == B->val && dfs(A->left, B->right) && dfs(A->right, B->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
};
```