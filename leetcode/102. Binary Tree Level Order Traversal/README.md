# [102. Binary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal/)

<p>Given the <code>root</code> of a binary tree, return <em>the level order traversal of its nodes' values</em>. (i.e., from left to right, level by level).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;">
<pre><strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> [[3],[9,20],[15,7]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [[1]]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Binary Tree Zigzag Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
* [Binary Tree Level Order Traversal II (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)
* [Minimum Depth of Binary Tree (Easy)](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
* [Binary Tree Vertical Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-vertical-order-traversal/)
* [Average of Levels in Binary Tree (Easy)](https://leetcode.com/problems/average-of-levels-in-binary-tree/)
* [N-ary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)
* [Cousins in Binary Tree (Easy)](https://leetcode.com/problems/cousins-in-binary-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q{{root}};
        while (q.size()) {
            ans.emplace_back();
            for (int cnt = q.size(); cnt--; ) {
                auto n = q.front();
                q.pop();
                ans.back().push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        return ans;
    }
};
```