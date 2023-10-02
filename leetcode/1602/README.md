# [1602. Find Nearest Right Node in Binary Tree (Medium)](https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/)

<p>Given the <code>root</code> of a binary tree and a node <code>u</code> in the tree, return <em>the <strong>nearest</strong> node on the <strong>same level</strong> that is to the <strong>right</strong> of</em> <code>u</code><em>, or return</em> <code>null</code> <em>if </em><code>u</code> <em>is the rightmost node in its level</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/24/p3.png" style="width: 241px; height: 161px;">
<pre><strong>Input:</strong> root = [1,2,3,null,4,5,6], u = 4
<strong>Output:</strong> 5
<strong>Explanation:</strong> The nearest node on the same level to the right of node 4 is node 5.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/23/p2.png" style="width: 101px; height: 161px;">
<pre><strong>Input:</strong> root = [3,null,4,2], u = 2
<strong>Output:</strong> null
<strong>Explanation:</strong> There are no nodes to the right of 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>All values in the tree are <strong>distinct</strong>.</li>
	<li><code>u</code> is a node in the binary tree rooted at <code>root</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*> q{{root}};
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto n = q.front();
                q.pop();
                if (n == u) return cnt ? q.front() : nullptr;
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        return nullptr;
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        int depth = -1;
        TreeNode *ans = nullptr;
        function<bool(TreeNode*, int)> dfs = [&](TreeNode *node, int d) {
            if (!node) return false;
            if (node == u) {
                depth = d;
                return false;
            } else if (d == depth) {
                ans = node;
                return true;
            }
            return dfs(node->left, d + 1) || dfs(node->right, d + 1);
        };
        dfs(root, 0);
        return ans;
    }
};
```