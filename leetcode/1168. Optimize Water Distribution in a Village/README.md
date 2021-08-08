# [1168. Optimize Water Distribution in a Village (Hard)](https://leetcode.com/problems/optimize-water-distribution-in-a-village/)

<p>There are <code>n</code> houses in a village. We want to supply water for all the houses by building wells and laying pipes.</p>

<p>For each house <code>i</code>, we can either build a well inside it directly with cost <code>wells[i - 1]</code> (note the <code>-1</code> due to <strong>0-indexing</strong>), or pipe in water from another well to it. The costs to lay pipes between houses are given by the array <code>pipes</code>, where each <code>pipes[j] = [house1<sub>j</sub>, house2<sub>j</sub>, cost<sub>j</sub>]</code> represents the cost to connect <code>house1<sub>j</sub></code> and <code>house2<sub>j</sub></code> together using a pipe. Connections are bidirectional.</p>

<p>Return <em>the minimum total cost to supply water to all houses</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/05/22/1359_ex1.png" style="width: 189px; height: 196px;"></strong></p>

<pre><strong>Input:</strong> n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
<strong>Output:</strong> 3
<strong>Explanation: </strong>
The image shows the costs of connecting houses using pipes.
The best strategy is to build a well in the first house with cost 1 and connect the other houses to it with cost 2 so the total cost is 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>wells.length == n</code></li>
	<li><code>0 &lt;= wells[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= pipes.length &lt;= 10<sup>4</sup></code></li>
	<li><code>pipes[j].length == 3</code></li>
	<li><code>1 &lt;= house1<sub>j</sub>, house2<sub>j</sub> &lt;= n</code></li>
	<li><code>0 &lt;= cost<sub>j</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>house1<sub>j</sub> != house2<sub>j</sub></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/), [Minimum Spanning Tree](https://leetcode.com/tag/minimum-spanning-tree/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/optimize-water-distribution-in-a-village/
// Author: github.com/lzl124631x
// Time: O(E + (V + E) * log(V + E))
// Space: O(E + V)
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& W, vector<vector<int>>& P) {
        vector<vector<pair<int, int>>> G(n);
        for (auto &p : P) {
            int u = p[0] - 1, v = p[1] - 1, cost = p[2];
            G[u].emplace_back(v, cost);
            G[v].emplace_back(u, cost);
        }
        unordered_set<int> seen;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // cost, index
        for (int i = 0; i < n; ++i) pq.emplace(W[i], i);
        int ans = 0;
        while (seen.size() < n) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (seen.count(u)) continue;
            seen.insert(u);
            ans += cost;
            for (auto &[v, c] : G[u]) {
                if (seen.count(v)) continue;
                pq.emplace(c, v);
            }
        }
        return ans;
    }
};
```