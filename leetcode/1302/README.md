# [1302. Deepest Leaves Sum (Medium)](https://leetcode.com/problems/deepest-leaves-sum/)

Given a binary tree, return the sum of values of its deepest leaves.
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/07/31/1483_ex1.png" style="width: 273px; height: 265px;"></strong></p>

<pre><strong>Input:</strong> root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
<strong>Output:</strong> 15
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is between&nbsp;<code>1</code>&nbsp;and&nbsp;<code>10^4</code>.</li>
	<li>The value of nodes is between&nbsp;<code>1</code>&nbsp;and&nbsp;<code>100</code>.</li>
</ul>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/deepest-leaves-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int getDepth(TreeNode *root) {
        return root ? 1 + max(getDepth(root->left), getDepth(root->right)) : 0;
    }
    int getSumAtDepth(TreeNode *root, int d, int depth) {
        if (!root) return 0;
        if (d == depth) return root->val;
        return getSumAtDepth(root->left, d + 1, depth) + getSumAtDepth(root->right, d + 1, depth);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int depth = getDepth(root);
        return getSumAtDepth(root, 1, depth);
    }
};
```

## Solution 2. BFS

```cpp
// OJ: https://leetcode.com/problems/deepest-leaves-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        q.push(root);
        while (q.size()) {
            int cnt = q.size();
            ans = 0;
            while (cnt--) {
                auto node = q.front();
                q.pop();
                ans += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};
```