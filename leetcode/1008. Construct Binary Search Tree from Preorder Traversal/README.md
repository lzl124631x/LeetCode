# [1008. Construct Binary Search Tree from Preorder Traversal (Medium)](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

<p>Return the root node of a binary <strong>search</strong> tree that matches the given <code>preorder</code> traversal.</p>

<p><em>(Recall that a binary search tree&nbsp;is a binary tree where for every <font face="monospace">node</font>, any descendant of <code>node.left</code> has a value <code>&lt;</code>&nbsp;<code>node.val</code>, and any descendant of <code>node.right</code> has a value <code>&gt;</code>&nbsp;<code>node.val</code>.&nbsp; Also recall that a preorder traversal&nbsp;displays the value of the&nbsp;<code>node</code> first, then traverses <code>node.left</code>, then traverses <code>node.right</code>.)</em></p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[8,5,1,7,10,12]</span>
<strong>Output: </strong><span id="example-output-1">[8,5,10,1,7,null,12]
<img alt="" src="https://assets.leetcode.com/uploads/2019/03/06/1266.png" style="height: 200px; width: 306px;"></span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong>&nbsp;</p>

<ol>
	<li><code>1 &lt;= preorder.length &lt;= 100</code></li>
	<li>The values of <code>preorder</code> are distinct.</li>
</ol>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
    TreeNode* construct(vector<int> &preorder, int begin, int end) {
        if (begin >= end) return NULL;
        auto root = new TreeNode(preorder[begin]);
        int i = begin + 1;
        while (i < end && preorder[i] < preorder[begin]) ++i;
        root->left = construct(preorder, begin + 1, i);
        root->right = construct(preorder, i, end);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, 0, preorder.size());
    }
};
```