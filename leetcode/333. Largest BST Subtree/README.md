# [333. Largest BST Subtree (Medium)](https://leetcode.com/problems/largest-bst-subtree/)

<p>Given the root of a binary tree, find the largest subtree, which is also a Binary Search Tree (BST), where the largest means subtree has the largest number of nodes.</p>

<p>A <strong>Binary Search Tree (BST)</strong> is a tree in which all the nodes follow the below-mentioned properties:</p>

<ul>
	<li>The left subtree values are less than the value of their parent (root) node's value.</li>
	<li>The right subtree values are greater than the value of their parent (root) node's value.</li>
</ul>

<p><strong>Note:</strong> A subtree must include all of its descendants.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/10/17/tmp.jpg" style="width: 571px; height: 302px;"></strong></p>

<pre><strong>Input:</strong> root = [10,5,15,1,8,null,7]
<strong>Output:</strong> 3
<strong>Explanation: </strong>The Largest BST Subtree in this case is the highlighted one. The return value is the subtree's size, which is 3.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [4,2,7,2,3,5,null,2,null,null,null,null,null,1]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Can you figure out ways to solve it with <code>O(n)</code> time complexity?</p>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

## Solution 1. Post-order Traversal

```cpp
// OJ: https://leetcode.com/problems/largest-bst-subtree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    array<int, 3> dfs(TreeNode *root) { // min, max, count. If invalid, count = -1
        if (!root) return {INT_MAX,INT_MIN,0};
        auto left = dfs(root->left), right = dfs(root->right);
        bool valid = left[2] != -1 && right[2] != -1 && left[1] < root->val && right[0] > root->val;
        if (valid) ans = max(ans, 1 + left[2] + right[2]);
        return {left[2] ? left[0] : root->val, right[2] ? right[1] : root->val, valid ? 1 + left[2] + right[2] : -1};
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```