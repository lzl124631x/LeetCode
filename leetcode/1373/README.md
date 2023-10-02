# [1373. Maximum Sum BST in Binary Tree (Hard)](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/)

<p>Given a <strong>binary tree</strong> <code>root</code>, the task is to return the maximum sum of all keys of <strong>any</strong>&nbsp;sub-tree which is also a Binary Search Tree (BST).</p>

<p>Assume a BST is defined as follows:</p>

<ul>
	<li>The left subtree of a node contains only nodes with keys&nbsp;<strong>less than</strong>&nbsp;the node's key.</li>
	<li>The right subtree of a node contains only nodes with keys&nbsp;<strong>greater than</strong>&nbsp;the node's key.</li>
	<li>Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/01/30/sample_1_1709.png" style="width: 320px; height: 250px;"></p>

<pre><strong>Input:</strong> root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
<strong>Output:</strong> 20
<strong>Explanation:</strong> Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/01/30/sample_2_1709.png" style="width: 134px; height: 180px;"></p>

<pre><strong>Input:</strong> root = [4,3,null,1,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [-4,-2,-5]
<strong>Output:</strong> 0
<strong>Explanation:</strong> All values are negatives. Return an empty BST.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> 6
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> root = [5,4,8,3,null,6,3]
<strong>Output:</strong> 7
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>Each tree has at most <code>40000</code> nodes..</li>
	<li>Each node's value is between <code>[-4 * 10^4&nbsp;, 4 * 10^4]</code>.</li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    int ans = 0;
    pair<int, int> postorder(TreeNode *root) {
        pair<int, int> r{root->val, root->val};
        bool isBST = true;
        if (root->left) {
            auto left = postorder(root->left);
            if (root->val <= left.second) isBST = false;
            r.second = max(left.second, root->val);
            r.first = min(left.first, root->val);
        }
        if (root->right) {
            auto right = postorder(root->right);
            if (root->val >= right.first) isBST = false;
            r.second = max(right.second, root->val);
            r.first = min(right.first, root->val);
        }
        root->val += (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
        if (isBST) ans = max(ans, root->val);
        return isBST ? r :  pair<int,int>{ INT_MIN, INT_MAX };
    }
public:
    int maxSumBST(TreeNode* root) {
        if (!root) return 0;
        postorder(root);
        return ans;
    }
};
```