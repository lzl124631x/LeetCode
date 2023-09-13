# [2492. Minimum Score of a Path Between Two Cities (Medium)](https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities)

<p>You are given a positive integer <code>n</code> representing <code>n</code> cities numbered from <code>1</code> to <code>n</code>. You are also given a <strong>2D</strong> array <code>roads</code> where <code>roads[i] = [a<sub>i</sub>, b<sub>i</sub>, distance<sub>i</sub>]</code> indicates that there is a <strong>bidirectional </strong>road between cities <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> with a distance equal to <code>distance<sub>i</sub></code>. The cities graph is not necessarily connected.</p>
<p>The <strong>score</strong> of a path between two cities is defined as the <strong>minimum </strong>distance of a road in this path.</p>
<p>Return <em>the <strong>minimum </strong>possible score of a path between cities </em><code>1</code><em> and </em><code>n</code>.</p>
<p><strong>Note</strong>:</p>
<ul>
	<li>A path is a sequence of roads between two cities.</li>
	<li>It is allowed for a path to contain the same road <strong>multiple</strong> times, and you can visit cities <code>1</code> and <code>n</code> multiple times along the path.</li>
	<li>The test cases are generated such that there is <strong>at least</strong> one path between <code>1</code> and <code>n</code>.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/12/graph11.png" style="width: 190px; height: 231px;">
<pre><strong>Input:</strong> n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The path from city 1 to 4 with the minimum score is: 1 -&gt; 2 -&gt; 4. The score of this path is min(9,5) = 5.
It can be shown that no other path has less score.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/12/graph22.png" style="width: 190px; height: 231px;">
<pre><strong>Input:</strong> n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The path from city 1 to 4 with the minimum score is: 1 -&gt; 2 -&gt; 1 -&gt; 3 -&gt; 4. The score of this path is min(2,2,4,7) = 2.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= roads.length &lt;= 10<sup>5</sup></code></li>
	<li><code>roads[i].length == 3</code></li>
	<li><code>1 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>1 &lt;= distance<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>There are no repeated edges.</li>
	<li>There is at least one path between <code>1</code> and <code>n</code>.</li>
</ul>

**Companies**:
[Unbxd](https://leetcode.com/company/unbxd)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Checking Existence of Edge Length Limited Paths (Hard)](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/)
* [Checking Existence of Edge Length Limited Paths II (Hard)](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N + E)
class Solution {
public:
    int minScore(int n, vector<vector<int>>& E) {
        vector<vector<pair<int, int>>> G(n);
        for (auto &e : E) {
            int u = e[0] - 1, v = e[1] - 1, dist = e[2];
            G[u].emplace_back(v, dist);
            G[v].emplace_back(u, dist);
        }
        vector<bool> seen(n);
        int ans = INT_MAX;
        function<void(int)> dfs = [&](int u) {
            if (seen[u]) return;
            seen[u] = true;
            for (auto &[v, dist] : G[u]) {
                ans = min(ans, dist);
                dfs(v);
            }
        };
        dfs(0);
        return ans;
    }
};
```

## Solution 2. Union Find

```cpp
// OJ: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities
// Author: github.com/lzl124631x
// Time: O(N + ElogN). This can be reduced to O(N + E) if we use union-by-rank.
// Space: O(N)
class Solution {
public:
    int minScore(int n, vector<vector<int>>& E) {
        vector<int> id(n), score(n, INT_MAX);
        iota(begin(id), end(id), 0);
        function<int(int)> find = [&](int a) {
            return id[a] == a ? a : (id[a] = find(id[a]));
        };
        auto connect = [&](int u, int v, int dist) {
            int p = find(u), q = find(v);
            id[q] = p;
            score[p] = min({score[p], score[q], dist});
        };
        for (auto &e : E) {
            int u = e[0] - 1, v = e[1] - 1, dist = e[2];
            connect(u, v, dist);
        }
        return score[find(0)];
    }
};
```