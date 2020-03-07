# [1372. Longest ZigZag Path in a Binary Tree (Medium)](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree)

<p>Given a binary tree <code>root</code>, a&nbsp;ZigZag path for a binary tree is defined as follow:</p>

<ul>
	<li>Choose <strong>any </strong>node in the binary tree and a direction (right or left).</li>
	<li>If the current direction is right then move to the right child of the current node otherwise move to the left child.</li>
	<li>Change the direction from right to left or right to left.</li>
	<li>Repeat the second and third step until you can't move in the tree.</li>
</ul>

<p>Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).</p>

<p>Return&nbsp;the longest <strong>ZigZag</strong> path contained in that tree.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/01/22/sample_1_1702.png" style="width: 151px; height: 283px;"></strong></p>

<pre><strong>Input:</strong> root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Longest ZigZag path in blue nodes (right -&gt; left -&gt; right).
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/01/22/sample_2_1702.png" style="width: 120px; height: 253px;"></strong></p>

<pre><strong>Input:</strong> root = [1,1,1,null,1,null,null,1,1,null,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Longest ZigZag path in blue nodes (left -&gt; right -&gt; left -&gt; right).
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>Each tree has at most <code>50000</code> nodes..</li>
	<li>Each node's value is between <code>[1, 100]</code>.</li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int A = 0;
    pair<int, int> postorder(TreeNode* root)  {
        if (!root || (!root->left && !root->right)) return { 0, 0 };
        pair<int, int> ans;
        if (root->left) {
            auto left = postorder(root->left);
            ans.first = 1 + left.second;
        }
        if (root->right) {
            auto right = postorder(root->right);
            ans.second = 1 + right.first;
        }
        A = max({ A, ans.first, ans.second });
        return ans;
    }
public:
    int longestZigZag(TreeNode* root) {
        postorder(root);
        return A;
    }
};
```