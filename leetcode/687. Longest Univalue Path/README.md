# [687. Longest Univalue Path (Easy)](https://leetcode.com/problems/longest-univalue-path/)

<p>Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.</p>

<p>The length of path between two nodes is represented by the number of edges between them.</p>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<p><strong>Input:</strong></p>

<pre>              5
             / \
            4   5
           / \   \
          1   1   5
</pre>

<p><strong>Output:</strong>&nbsp;2</p>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<p><strong>Input:</strong></p>

<pre>              1
             / \
            4   5
           / \   \
          4   4   5
</pre>

<p><strong>Output:</strong>&nbsp;2</p>

<p>&nbsp;</p>

<p><b>Note:</b> The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.</p>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Binary Tree Maximum Path Sum (Hard)](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
* [Count Univalue Subtrees (Medium)](https://leetcode.com/problems/count-univalue-subtrees/)
* [Path Sum III (Easy)](https://leetcode.com/problems/path-sum-iii/)

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
        if (root->left && root->left->val == root->val) ++left;
        else left = 0;
        if (root->right && root->right->val == root->val) ++right;
        else right = 0;
        ans = max(ans, left + right);
        return max(left, right);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```