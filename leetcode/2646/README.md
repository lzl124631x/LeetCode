# [2646. Minimize the Total Price of the Trips (Hard)](https://leetcode.com/problems/minimize-the-total-price-of-the-trips)

<p>There exists an undirected and unrooted tree with <code>n</code> nodes indexed from <code>0</code> to <code>n - 1</code>. You are given the integer <code>n</code> and a 2D integer array <code>edges</code> of length <code>n - 1</code>, where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>Each node has an associated price. You are given an integer array <code>price</code>, where <code>price[i]</code> is the price of the <code>i<sup>th</sup></code> node.</p>

<p>The <strong>price sum</strong> of a given path is the sum of the prices of all nodes lying on that path.</p>

<p>Additionally, you are given a 2D integer array <code>trips</code>, where <code>trips[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> indicates that you start the <code>i<sup>th</sup></code> trip from the node <code>start<sub>i</sub></code> and travel to the node <code>end<sub>i</sub></code> by any path you like.</p>

<p>Before performing your first trip, you can choose some <strong>non-adjacent</strong> nodes and halve the prices.</p>

<p>Return <em>the minimum total price sum to perform all the given trips</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/03/16/diagram2.png" style="width: 541px; height: 181px;" />
<pre>
<strong>Input:</strong> n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6], trips = [[0,3],[2,1],[2,3]]
<strong>Output:</strong> 23
<strong>Explanation:</strong> The diagram above denotes the tree after rooting it at node 2. The first part shows the initial tree and the second part shows the tree after choosing nodes 0, 2, and 3, and making their price half.
For the 1<sup>st</sup> trip, we choose path [0,1,3]. The price sum of that path is 1 + 2 + 3 = 6.
For the 2<sup>nd</sup> trip, we choose path [2,1]. The price sum of that path is 2 + 5 = 7.
For the 3<sup>rd</sup> trip, we choose path [2,1,3]. The price sum of that path is 5 + 2 + 3 = 10.
The total price sum of all trips is 6 + 7 + 10 = 23.
It can be proven, that 23 is the minimum answer that we can achieve.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/03/16/diagram3.png" style="width: 456px; height: 111px;" />
<pre>
<strong>Input:</strong> n = 2, edges = [[0,1]], price = [2,2], trips = [[0,0]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The diagram above denotes the tree after rooting it at node 0. The first part shows the initial tree and the second part shows the tree after choosing node 0, and making its price half.
For the 1<sup>st</sup> trip, we choose path [0]. The price sum of that path is 1.
The total price sum of all trips is 1. It can be proven, that 1 is the minimum answer that we can achieve.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>edges</code> represents a valid tree.</li>
	<li><code>price.length == n</code></li>
	<li><code>price[i]</code> is an even integer.</li>
	<li><code>1 &lt;= price[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= trips.length &lt;= 100</code></li>
	<li><code>0 &lt;= start<sub>i</sub>, end<sub>i</sub>&nbsp;&lt;= n - 1</code></li>
</ul>


**Companies**:
[Adobe](https://leetcode.com/company/adobe), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search), [Graph](https://leetcode.com/tag/graph)

**Hints**:
* The final answer is the price[i] * freq[i], where freq[i] is the number of times node i was visited during the trip, and price[i] is the final price.
* To find freq[i] we will use dfs or bfs for each trip and update every node on the path start and end.
* Finally, to find the final price[i] we will use dynamic programming on the tree. Let dp(v, 0/1) denote the minimum total price with the node v’s price being halved or not.

## Solution 1. Post-order Traversal

1. Build Graph (`O(E)` time, `O(E)` space)
2. For each trip, increment the frequency of the nodes in the path. (`O(TN)` time, `O(N)` space)
3. DP on tree: Post-order traversal to aggregate the two options (halve, not halve) from leaves to root. The answer is the minimum of (halve, not halve) options of root node.

```cpp
// OJ: https://leetcode.com/problems/minimize-the-total-price-of-the-trips
// Author: github.com/lzl124631x
// Time: O(E + TN)
// Space: O(E + N)
class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& E, vector<int>& P, vector<vector<int>>& T) {
        vector<vector<int>> G(n);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> cnt(n);
        function<bool(int, int, int)> dfs = [&](int u, int goal, int prev) {
            ++cnt[u];
            if (u == goal) return true;
            for (int v : G[u]) {
                if (v == prev) continue;
                if (dfs(v, goal, u)) return true;
            }
            --cnt[u];
            return false;
        };
        for (auto &t : T) dfs(t[0], t[1], -1);
        function<pair<int, int>(int, int)> dfs2 = [&](int u, int prev) {
            int halve = cnt[u] * P[u] / 2, skip = cnt[u] * P[u];
            for (int v : G[u]) {
                if (v == prev) continue;
                auto [h, s] = dfs2(v, u);
                halve += s;
                skip += min(h, s);
            }
            return pair<int, int>{halve, skip};
        };
        auto [h, s] = dfs2(0, -1);
        return min(h, s);
    }
};
```