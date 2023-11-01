# [515. Find Largest Value in Each Tree Row (Medium)](https://leetcode.com/problems/find-largest-value-in-each-tree-row)

<p>Given the <code>root</code> of a binary tree, return <em>an array of the largest value in each row</em> of the tree <strong>(0-indexed)</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg" style="width: 300px; height: 172px;" />
<pre>
<strong>Input:</strong> root = [1,3,2,5,3,null,9]
<strong>Output:</strong> [1,3,9]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1,2,3]
<strong>Output:</strong> [1,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree will be in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:
[Facebook](https://leetcode.com/company/facebook), [LinkedIn](https://leetcode.com/company/linkedin)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search), [Binary Tree](https://leetcode.com/tag/binary-tree)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode*> q{{root}};
        while (q.size()) {
            int cnt = q.size(), maxVal = INT_MIN;
            while (cnt--) {
                auto n = q.front();
                q.pop();
                maxVal = max(maxVal, n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        function<void(TreeNode*, int)> dfs = [&](TreeNode *node, int d) {
            if (!node) return;
            if (d == ans.size()) ans.push_back(INT_MIN);
            ans[d] = max(ans[d], node->val);
            dfs(node->left, d + 1);
            dfs(node->right, d + 1);
        };
        dfs(root, 0);
        return ans;
    }
};
```