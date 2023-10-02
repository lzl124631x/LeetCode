# [2385. Amount of Time for Binary Tree to Be Infected (Medium)](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected)

<p>You are given the <code>root</code> of a binary tree with <strong>unique</strong> values, and an integer <code>start</code>. At minute <code>0</code>, an <strong>infection</strong> starts from the node with value <code>start</code>.</p>

<p>Each minute, a node becomes infected if:</p>

<ul>
	<li>The node is currently uninfected.</li>
	<li>The node is adjacent to an infected node.</li>
</ul>

<p>Return <em>the number of minutes needed for the entire tree to be infected.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/25/image-20220625231744-1.png" style="width: 400px; height: 306px;">
<pre><strong>Input:</strong> root = [1,5,3,null,4,10,6,9,2], start = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/25/image-20220625231812-2.png" style="width: 75px; height: 66px;">
<pre><strong>Input:</strong> root = [1], start = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> At minute 0, the only node in the tree is infected so we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>Each node has a <strong>unique</strong> value.</li>
	<li>A node with a value of <code>start</code> exists in the tree.</li>
</ul>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Maximum Depth of Binary Tree (Easy)](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
* [Shortest Path to Get Food (Easy)](https://leetcode.com/problems/shortest-path-to-get-food/)
* [All Nodes Distance K in Binary Tree (Easy)](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        int ans = 0, sd = -1;
        typedef pair<bool, int> PBI;
        function<PBI(TreeNode*, int)> dfs = [&](TreeNode *n, int depth) {
            if (!n) return PBI{false, 0};
            bool found = start == n->val;
            auto [lf, ld] = dfs(n->left, depth + 1);
            auto [rf, rd] = dfs(n->right, depth + 1);
            if (found) {
                sd = depth;
                ans = max(ans, max(ld, rd));
            }
            if (lf) ans = max(ans, sd - depth + rd);
            if (rf) ans = max(ans, sd - depth + ld);
            return PBI{lf || rf || found, 1 + max(ld, rd)};
        };
        dfs(root, 0);
        return ans;
    }
};
```