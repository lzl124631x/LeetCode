# [549. Binary Tree Longest Consecutive Sequence II (Medium)](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/)

<p>Given the <code>root</code> of a binary tree, return <em>the length of the longest consecutive path in the tree</em>.</p>

<p>A consecutive path is a path where the values of the consecutive nodes in the path differ by one. This path can be either increasing or decreasing.</p>

<ul>
	<li>For example, <code>[1,2,3,4]</code> and <code>[4,3,2,1]</code> are both considered valid, but the path <code>[1,2,4,3]</code> is not valid.</li>
</ul>

<p>On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/consec2-1-tree.jpg" style="width: 207px; height: 183px;">
<pre><strong>Input:</strong> root = [1,2,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The longest consecutive path is [1, 2] or [2, 1].
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/consec2-2-tree.jpg" style="width: 207px; height: 183px;">
<pre><strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest consecutive path is [1, 2, 3] or [3, 2, 1].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 3 * 10<sup>4</sup>]</code>.</li>
	<li><code>-3 * 10<sup>4</sup> &lt;= Node.val &lt;= 3 * 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Binary Tree Longest Consecutive Sequence (Medium)](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/)

## Solution 1. Post-order traversal

```cpp
// OJ: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    pair<int, int> dfs(TreeNode *root) {
        if (!root) return {0, 0};
        auto [linc, ldec] = dfs(root->left);
        auto [rinc, rdec] = dfs(root->right);
        if (root->left) {
            if (root->val != root->left->val + 1) linc = 0;
            if (root->val != root->left->val - 1) ldec = 0;
        }
        if (root->right) {
            if (root->val != root->right->val + 1) rinc = 0;
            if (root->val != root->right->val - 1) rdec = 0;
        }
        ans = max({ ans, ldec + rinc + 1, rdec + linc + 1 });
        return { max(linc, rinc) + 1, max(ldec, rdec) + 1 };
    }
public:
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```