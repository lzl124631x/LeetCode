# [671. Second Minimum Node In a Binary Tree (Easy)](https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/)

<p>Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly <code>two</code> or <code>zero</code> sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property&nbsp;<code>root.val = min(root.left.val, root.right.val)</code>&nbsp;always holds.</p>

<p>Given such a binary tree, you need to output the <b>second minimum</b> value in the set made of all the nodes' value in the whole tree.</p>

<p>If no such second minimum value exists, output -1 instead.</p>

<p>&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/smbt1.jpg" style="width: 431px; height: 302px;">
<pre><strong>Input:</strong> root = [2,2,5,null,null,5,7]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The smallest value is 2, the second smallest value is 5.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/smbt2.jpg" style="width: 321px; height: 182px;">
<pre><strong>Input:</strong> root = [2,2,2]
<strong>Output:</strong> -1
<strong>Explanation:</strong> The smallest value is 2, but there isn't any second smallest value.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 25]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>root.val == min(root.left.val, root.right.val)</code>&nbsp;for each internal node of the tree.</li>
</ul>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Kth Smallest Element in a BST (Medium)](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    long mn, ans = LONG_MAX;
    void dfs(TreeNode *root) {
        if (root->left) {
            if (root->left->val == mn) dfs(root->left);
            else ans = min(ans, (long)root->left->val);
        }
        if (root->right) {
            if (root->right->val == mn) dfs(root->right);
            else ans = min(ans, (long)root->right->val);
        }
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        mn = root->val;
        dfs(root);
        return ans == LONG_MAX ? -1 : ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    long mn, ans = LONG_MAX;
    void dfs(TreeNode *root) {
        if (!root) return;
        if (root->val > mn && root->val < ans) ans = min(ans, (long)root->val);
        if (root->val == mn) {
            dfs(root->left);
            dfs(root->right);
        }
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        mn = root->val;
        dfs(root);
        return ans == LONG_MAX ? -1 : ans;
    }
};
```