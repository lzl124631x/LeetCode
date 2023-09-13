# [1325. Delete Leaves With a Given Value (Medium)](https://leetcode.com/problems/delete-leaves-with-a-given-value/)

<p>Given a binary tree&nbsp;<code>root</code>&nbsp;and an integer&nbsp;<code>target</code>, delete all the&nbsp;<strong>leaf nodes</strong>&nbsp;with value <code>target</code>.</p>

<p>Note&nbsp;that once you delete a leaf node with value <code>target</code><strong>,&nbsp;</strong>if it's parent node becomes a leaf node and has the value <code><font face="monospace">target</font></code>, it should also be deleted (you need to continue doing that until you can't).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/01/09/sample_1_1684.png" style="width: 550px; height: 120px;"></strong></p>

<pre><strong>Input:</strong> root = [1,2,3,2,null,2,4], target = 2
<strong>Output:</strong> [1,null,3,null,4]
<strong>Explanation:</strong> Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/01/09/sample_2_1684.png" style="width: 300px; height: 120px;"></strong></p>

<pre><strong>Input:</strong> root = [1,3,3,3,2], target = 3
<strong>Output:</strong> [1,3,null,null,2]
</pre>

<p><strong>Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/01/15/sample_3_1684.png" style="width: 420px; height: 150px;"></strong></p>

<pre><strong>Input:</strong> root = [1,2,null,2,null,2], target = 2
<strong>Output:</strong> [1]
<strong>Explanation:</strong> Leaf nodes in green with value (target = 2) are removed at each step.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> root = [1,1,1], target = 1
<strong>Output:</strong> []
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> root = [1,2,3], target = 1
<strong>Output:</strong> [1,2,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target&nbsp;&lt;= 1000</code></li>
	<li>Each tree has at most <code>3000</code> nodes.</li>
	<li>Each node's value is between <code>[1, 1000]</code>.</li>
</ul>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/delete-leaves-with-a-given-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    TreeNode* postorder(TreeNode *node, int target) {
        if (!node) return NULL;
        node->left = postorder(node->left, target);
        node->right = postorder(node->right, target);
        return !node->left && !node->right && node->val == target ? NULL : node;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return postorder(root, target);
    }
};
```