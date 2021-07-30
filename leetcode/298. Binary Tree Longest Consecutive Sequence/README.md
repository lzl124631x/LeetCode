# [298. Binary Tree Longest Consecutive Sequence (Medium)](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/)

<p>Given the <code>root</code> of a binary tree, return <em>the length of the longest consecutive sequence path</em>.</p>

<p>The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path needs to be from parent to child (cannot be the reverse).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/consec1-1-tree.jpg" style="width: 322px; height: 421px;">
<pre><strong>Input:</strong> root = [1,null,3,2,4,null,null,null,5]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Longest consecutive sequence path is 3-4-5, so return 3.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/consec1-2-tree.jpg" style="width: 262px; height: 421px;">
<pre><strong>Input:</strong> root = [2,null,3,2,null,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 3 * 10<sup>4</sup>]</code>.</li>
	<li><code>-3 * 10<sup>4</sup> &lt;= Node.val &lt;= 3 * 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Longest Consecutive Sequence (Medium)](https://leetcode.com/problems/longest-consecutive-sequence/)
* [Binary Tree Longest Consecutive Sequence II (Medium)](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/)

## Solution 1. Pre-order Traversal

```cpp
// OJ: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    void dfs(TreeNode *root, TreeNode *parent = NULL, int length = 1) {
        if (!root) return;
        length = parent && parent->val + 1 == root->val ? length + 1 : 1;
        ans = max(ans, length);
        dfs(root->left, root, length);
        dfs(root->right, root, length);
    }
public:
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

## Solution 2. Post-order Traversal

```cpp
// OJ: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    int dfs(TreeNode *root) {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        if (root->left && root->val + 1 != root->left->val) left = 0;
        if (root->right && root->val + 1 != root->right->val) right = 0;
        ans = max({ ans, 1 + left, 1 + right });
        return 1 + max(left, right);
    }
public:
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```