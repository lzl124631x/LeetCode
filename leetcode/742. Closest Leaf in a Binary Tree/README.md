# [742. Closest Leaf in a Binary Tree (Medium)](https://leetcode.com/problems/closest-leaf-in-a-binary-tree)

<p>Given the <code>root</code> of a binary tree where every node has <strong>a unique value</strong> and a target integer <code>k</code>, return <em>the value of the <strong>nearest leaf node</strong> to the target </em><code>k</code><em> in the tree</em>.</p>
<p><strong>Nearest to a leaf</strong> means the least number of edges traveled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/closest1-tree.jpg" style="width: 224px; height: 145px;">
<pre><strong>Input:</strong> root = [1,3,2], k = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> Either 2 or 3 is the nearest leaf node to the target of 1.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/closest2-tree.jpg" style="width: 64px; height: 65px;">
<pre><strong>Input:</strong> root = [1], k = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> The nearest leaf node is the root node itself.
</pre>
<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/closest3-tree.jpg" style="width: 464px; height: 384px;">
<pre><strong>Input:</strong> root = [1,2,3,4,null,null,null,5,null,6], k = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 1000]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
	<li>All the values of the tree are <strong>unique</strong>.</li>
	<li>There exist some node in the tree where <code>Node.val == k</code>.</li>
</ul>

**Companies**:
[Facebook](https://leetcode.com/company/facebook), [Databricks](https://leetcode.com/company/databricks), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/closest-leaf-in-a-binary-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        int Inf = 1e9, minDist = Inf, ans = -1;
        function<array<int, 3>(TreeNode*)> dfs = [&](TreeNode *root) -> array<int, 3> { // dist to target node, the depth and id of the node on the other subtree with the minimum depth
            if (!root) return {Inf, Inf, -1};
            if (!root->left && !root->right) {
                if (root->val == k) {
                    minDist = 0;
                    ans = k;
                    return {0, 0, root->val};
                }
                return {Inf, 0, root->val};
            }
            auto [a, b, c] = dfs(root->left);
            auto [d, e, f] = dfs(root->right);
            int dist = b + 1, id = c;
            if (e < b) dist = e + 1, id = f;
            if (root->val == k) {
                minDist = dist;
                ans = id;
                return {0, dist, id};
            }
            if (a >= Inf && d >= Inf) return {Inf, dist, id};
            if (d < Inf) swap(a, d), swap(b, e), swap(c, f);
            int sum = a + 1 + e;
            if (sum < minDist) {
                minDist = sum;
                ans = f;
            }
            return {a + 1, e + 1, f};
        };
        dfs(root);
        return ans;
    }
};
```