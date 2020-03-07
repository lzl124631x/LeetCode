# [1080. Insufficient Nodes in Root to Leaf Paths (Medium)](https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/)

<p>Given the <code>root</code>&nbsp;of a binary tree, consider all <em>root to leaf paths</em>: paths from the root&nbsp;to any leaf.&nbsp; (A leaf is a node with no children.)</p>

<p>A <code>node</code> is <em>insufficient</em> if&nbsp;<strong>every</strong> such root to leaf path intersecting this <code>node</code> has sum strictly less than&nbsp;<code>limit</code>.</p>

<p>Delete all insufficient nodes simultaneously, and return the root of the resulting&nbsp;binary tree.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/06/05/insufficient-11.png" style="width: 482px; height: 200px;">
Input: </strong>root = <span id="example-input-1-1">[1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14]</span>, limit = <span id="example-input-1-2">1</span>
<strong><img alt="" src="https://assets.leetcode.com/uploads/2019/06/05/insufficient-2.png" style="width: 258px; height: 200px;">
Output: </strong><span id="example-output-1">[1,2,3,4,null,null,7,8,9,null,14]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/06/05/insufficient-3.png" style="width: 292px; height: 200px;">
Input: </strong>root = <span id="example-input-2-1">[5,4,8,11,null,17,4,7,1,null,null,5,3]</span>, limit = <span id="example-input-2-2">22</span>
<strong><img alt="" src="https://assets.leetcode.com/uploads/2019/06/05/insufficient-4.png" style="width: 264px; height: 200px;">
Output: </strong><span id="example-output-2">[5,4,8,11,null,17,4,7,null,null,null,5]</span></pre>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>The given tree will have between <code>1</code> and <code>5000</code> nodes.</li>
	<li><code>-10^5&nbsp;&lt;= node.val &lt;= 10^5</code></li>
	<li><code>-10^9 &lt;= limit&nbsp;&lt;= 10^9</code></li>
</ol>

<div>
<div>&nbsp;</div>
</div>


## Solution 1.

In order to get the path sum from root to leaf node intersecting with the current node, we need to path sum from root to the current node, and the path sum from the current node to leaf node.

So we can use postorder traversal.

To get the "path sum from root to the current node", we can pass in the path sum from root to parent as parameter.

To get the "path sum from the current node to leaf node", we can use the return value of postorder tranversal -- returning the maximum path sum from the node to it's leaf nodes.

```cpp
// OJ: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    int postorder(TreeNode *root, long long sum, int limit) {
        if (!root) return 0;
        sum += root->val;
        int left = postorder(root->left, sum, limit);
        int right = postorder(root->right, sum, limit);
        if (sum + left < limit) root->left = NULL;
        if (sum + right < limit) root->right = NULL;
        return root->val + max(left, right);
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return postorder(root, 0, limit) < limit ? NULL : root;
    }
};
```