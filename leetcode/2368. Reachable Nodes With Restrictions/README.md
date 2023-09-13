# [2368. Reachable Nodes With Restrictions (Medium)](https://leetcode.com/problems/reachable-nodes-with-restrictions)

<p>There is an undirected tree with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code> and <code>n - 1</code> edges.</p>
<p>You are given a 2D integer array <code>edges</code> of length <code>n - 1</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree. You are also given an integer array <code>restricted</code> which represents <strong>restricted</strong> nodes.</p>
<p>Return <em>the <strong>maximum</strong> number of nodes you can reach from node </em><code>0</code><em> without visiting a restricted node.</em></p>
<p>Note that node <code>0</code> will <strong>not</strong> be a restricted node.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/15/ex1drawio.png" style="width: 402px; height: 322px;">
<pre><strong>Input:</strong> n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The diagram above shows the tree.
We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/15/ex2drawio.png" style="width: 412px; height: 312px;">
<pre><strong>Input:</strong> n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The diagram above shows the tree.
We have that [0,5,6] are the only nodes that can be reached from node 0 without visiting a restricted node.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>edges</code> represents a valid tree.</li>
	<li><code>1 &lt;= restricted.length &lt; n</code></li>
	<li><code>1 &lt;= restricted[i] &lt; n</code></li>
	<li>All the values of <code>restricted</code> are <strong>unique</strong>.</li>
</ul>

**Companies**:
[MakeMyTrip](https://leetcode.com/company/makemytrip)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Open the Lock (Medium)](https://leetcode.com/problems/open-the-lock/)
* [Minimum Jumps to Reach Home (Medium)](https://leetcode.com/problems/minimum-jumps-to-reach-home/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reachable-nodes-with-restrictions
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N + E)
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& E, vector<int>& R) {
        vector<vector<int>> G(n);
        unordered_set<int> r(begin(R), end(R));
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int ans = 0;
        function<void(int, int)> dfs = [&](int u, int prev) {
            ++ans;
            for (int v : G[u]) {
                if (v == prev || r.count(v)) continue;
                dfs(v, u);
            }
        };
        dfs(0, -1);
        return ans;
    }
};
```