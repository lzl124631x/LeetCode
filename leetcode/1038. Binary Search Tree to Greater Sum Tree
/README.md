# [1038. Binary Search Tree to Greater Sum Tree (Medium)](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)

<p>Given the root of a binary <strong>search</strong> tree with distinct values, modify it so that every <code>node</code>&nbsp;has a new value equal to the sum of the values of the original tree that are greater than or equal to <code>node.val</code>.</p>

<p>As a reminder, a&nbsp;<em>binary search tree</em> is a tree that satisfies these constraints:</p>

<ul>
	<li>The left subtree of a node contains only nodes with keys&nbsp;<strong>less than</strong>&nbsp;the node's key.</li>
	<li>The right subtree of a node contains only nodes with keys&nbsp;<strong>greater than</strong>&nbsp;the node's key.</li>
	<li>Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/05/02/tree.png" style="width: 280px; height: 191px;"></strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]</span>
<strong>Output: </strong><span id="example-output-1">[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]</span>
</pre>

<div>
<p>&nbsp;</p>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li>The number of nodes in the tree is between <code>1</code> and <code>100</code>.</li>
	<li>Each node will have value between <code>0</code> and <code>100</code>.</li>
	<li>The given tree is a binary search tree.</li>
</ol>

<div>
<div>
<div>&nbsp;</div>
</div>
</div>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Binary Search Tree](https://leetcode.com/tag/binary-search-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    int sum = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return NULL;
        bstToGst(root->right);
        root->val = (sum += root->val);
        bstToGst(root->left);
        return root;
    }
};
```