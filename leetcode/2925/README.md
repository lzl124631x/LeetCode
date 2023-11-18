# [2925. Maximum Score After Applying Operations on a Tree (Medium)](https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree)

<p>There is an undirected tree with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>, and rooted at node <code>0</code>. You are given&nbsp;a 2D integer array <code>edges</code> of length <code>n - 1</code>, where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>You are also given a <strong>0-indexed</strong> integer array <code>values</code> of length <code>n</code>, where <code>values[i]</code> is the <strong>value</strong> associated with the <code>i<sup>th</sup></code> node.</p>

<p>You start with a score of <code>0</code>. In one operation, you can:</p>

<ul>
	<li>Pick any node <code>i</code>.</li>
	<li>Add <code>values[i]</code> to your score.</li>
	<li>Set <code>values[i]</code> to <code>0</code>.</li>
</ul>

<p>A tree is <strong>healthy</strong> if the sum of values on the path from the root to any leaf node is different than zero.</p>

<p>Return <em>the <strong>maximum score</strong> you can obtain after performing these operations on the tree any number of times so that it remains <strong>healthy</strong>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/10/11/graph-13-1.png" style="width: 515px; height: 443px;" />
<pre>
<strong>Input:</strong> edges = [[0,1],[0,2],[0,3],[2,4],[4,5]], values = [5,2,5,2,1,1]
<strong>Output:</strong> 11
<strong>Explanation:</strong> We can choose nodes 1, 2, 3, 4, and 5. The value of the root is non-zero. Hence, the sum of values on the path from the root to any leaf is different than zero. Therefore, the tree is healthy and the score is values[1] + values[2] + values[3] + values[4] + values[5] = 11.
It can be shown that 11 is the maximum score obtainable after any number of operations on the tree.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/10/11/graph-14-2.png" style="width: 522px; height: 245px;" />
<pre>
<strong>Input:</strong> edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [20,10,9,7,4,3,5]
<strong>Output:</strong> 40
<strong>Explanation:</strong> We can choose nodes 0, 2, 3, and 4.
- The sum of values on the path from 0 to 4 is equal to 10.
- The sum of values on the path from 0 to 3 is equal to 10.
- The sum of values on the path from 0 to 5 is equal to 3.
- The sum of values on the path from 0 to 6 is equal to 5.
Therefore, the tree is healthy and the score is values[0] + values[2] + values[3] + values[4] = 40.
It can be shown that 40 is the maximum score obtainable after any number of operations on the tree.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>values.length == n</code></li>
	<li><code>1 &lt;= values[i] &lt;= 10<sup>9</sup></code></li>
	<li>The input is generated such that <code>edges</code> represents a valid tree.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search)

**Similar Questions**:
* [Sum of Distances in Tree (Hard)](https://leetcode.com/problems/sum-of-distances-in-tree)
* [Collect Coins in a Tree (Hard)](https://leetcode.com/problems/collect-coins-in-a-tree)

**Hints**:
* Let <code>dp[i]</code> be the maximum score we can get on the subtree rooted at <code>i</code> and <code>sum[i]</code> be the sum of all the values of the subtree rooted at <code>i</code>.
* If we don’t take <code>value[i]</code> into the final score, we can take all the nodes of the subtrees rooted at <code>i</code>’s children.
* If we take <code>value[i]</code> into the score, then each subtree rooted at its children should satisfy the constraints.
* <code>dp[x] = max(value[x] + sigma(dp[y]), sigma(sum[y]))</code>, where <code>y</code> is a direct child of <code>x</code>.

**Hints**:
* Let <code>dp[i]</code> be the maximum score we can get on the subtree rooted at <code>i</code> and <code>sum[i]</code> be the sum of all the values of the subtree rooted at <code>i</code>.
* If we don’t take <code>value[i]</code> into the final score, we can take all the nodes of the subtrees rooted at <code>i</code>’s children.
* If we take <code>value[i]</code> into the score, then each subtree rooted at its children should satisfy the constraints.
* <code>dp[x] = max(value[x] + sigma(dp[y]), sigma(sum[y]))</code>, where <code>y</code> is a direct child of <code>x</code>.

## Solution 1. Post-order Traversal

**Intuition**:
* Use post-order traversal. Visit children nodes first, then make a decision at the current node
* For each node visit, we have two options: take the score from the current node, or not.
* If we take the score from the current node, we need to make sure that all the child subtrees are healthy. So, each child subtree should return a `safe` value, meaning the maximum score we can get from the subtree while keeping the subtree healthy.
* If we DO NOT take the score from the current node, we can take all the scores from all the child subtrees. So, each child subtree should return a `sum` value, meaning the total score of all the nodes in the subtree.
* For a given node `u`, the safe score should be the maximum of `A[u] + childSafe` (the score we get if we take the score from `u`) and `childSum` (the score we get if we don't take the score from `u`)

```cpp
// OJ: https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& E, vector<int>& A) {
        typedef long long LL;
        int N = A.size();
        vector<vector<int>> G(N);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        function<pair<LL, LL>(int, int)> dfs = [&](int u, int prev) -> pair<LL, LL> {
            LL childSum = 0, childSafe = 0;
            for (int v : G[u]) {
                if (v == prev) continue;
                auto [safe, sum] = dfs(v, u);
                childSum += sum;
                childSafe += safe;
            }
            if (childSum == 0) return {0, A[u]}; // leaf node. The safe value is 0
            return {max(A[u] + childSafe, childSum), childSum + A[u]};
        };
        return dfs(0, -1).first;
    }
};
```