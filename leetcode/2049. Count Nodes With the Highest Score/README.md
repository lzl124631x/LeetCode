# [2049. Count Nodes With the Highest Score (Medium)](https://leetcode.com/problems/count-nodes-with-the-highest-score/)

<p>There is a <strong>binary</strong> tree rooted at <code>0</code> consisting of <code>n</code> nodes. The nodes are labeled from <code>0</code> to <code>n - 1</code>. You are given a <strong>0-indexed</strong> integer array <code>parents</code> representing the tree, where <code>parents[i]</code> is the parent of node <code>i</code>. Since node <code>0</code> is the root, <code>parents[0] == -1</code>.</p>

<p>Each node has a <strong>score</strong>. To find the score of a node, consider if the node and the edges connected to it were <strong>removed</strong>. The tree would become one or more <strong>non-empty</strong> subtrees. The <strong>size</strong> of a subtree is the number of the nodes in it. The <strong>score</strong> of the node is the <strong>product of the sizes</strong> of all those subtrees.</p>

<p>Return <em>the <strong>number</strong> of nodes that have the <strong>highest score</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="example-1" src="https://assets.leetcode.com/uploads/2021/10/03/example-1.png" style="width: 604px; height: 266px;">
<pre><strong>Input:</strong> parents = [-1,2,0,2,0]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
- The score of node 0 is: 3 * 1 = 3
- The score of node 1 is: 4 = 4
- The score of node 2 is: 1 * 1 * 2 = 2
- The score of node 3 is: 4 = 4
- The score of node 4 is: 4 = 4
The highest score is 4, and three nodes (node 1, node 3, and node 4) have the highest score.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="example-2" src="https://assets.leetcode.com/uploads/2021/10/03/example-2.png" style="width: 95px; height: 143px;">
<pre><strong>Input:</strong> parents = [-1,2,0]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
- The score of node 0 is: 2 = 2
- The score of node 1 is: 2 = 2
- The score of node 2 is: 1 * 1 = 1
The highest score is 2, and two nodes (node 0 and node 1) have the highest score.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == parents.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>parents[0] == -1</code></li>
	<li><code>0 &lt;= parents[i] &lt;= n - 1</code> for <code>i != 0</code></li>
	<li><code>parents</code> represents a valid binary tree.</li>
</ul>


**Similar Questions**:
* [Sum of Distances in Tree (Hard)](https://leetcode.com/problems/sum-of-distances-in-tree/)
* [Delete Nodes And Return Forest (Medium)](https://leetcode.com/problems/delete-nodes-and-return-forest/)
* [Maximum Product of Splitted Binary Tree (Medium)](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/)

## Solution 1. Post-order Traversal

Post-order traverse the tree. For each node, calculate its score by multiplying the node count of its left subtree, right subtree and nodes not in the current subtree (ignoring `0`). Count the nodes with the maximum score.

```cpp
// OJ: https://leetcode.com/problems/count-nodes-with-the-highest-score/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int countHighestScoreNodes(vector<int>& P) {
        long N = P.size(), ans = 0, maxScore = 0;
        vector<vector<int>> G(N); // build the graph -- G[i] is a list of the children of node `i`.
        for (int i = 1; i < N; ++i) G[P[i]].push_back(i);
        function<int(int)> dfs = [&](int u) { // Post-order traversal. Returns the size of the subtree rooted at node `u`.
            long score = 1, cnt = 1;
            for (int v : G[u]) {
                int c = dfs(v);
                cnt += c;
                score *= c;
            }
            long other = N - cnt; // The count of nodes not in this subtree rooted at node `u`.
            if (other) score *= other;
            if (score > maxScore) {
                maxScore = score;
                ans = 1;
            } else if (score == maxScore) ++ans;
            return cnt;
        };
        dfs(0);
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/count-nodes-with-the-highest-score/discuss/1537494/C%2B%2B-Post-order-Traversal