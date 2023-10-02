# [1514. Path with Maximum Probability (Medium)](https://leetcode.com/problems/path-with-maximum-probability/)

<p>You are given an undirected weighted graph of&nbsp;<code>n</code>&nbsp;nodes (0-indexed), represented by an edge list where&nbsp;<code>edges[i] = [a, b]</code>&nbsp;is an undirected edge connecting the nodes&nbsp;<code>a</code>&nbsp;and&nbsp;<code>b</code>&nbsp;with a probability of success of traversing that edge&nbsp;<code>succProb[i]</code>.</p>

<p>Given two nodes&nbsp;<code>start</code>&nbsp;and&nbsp;<code>end</code>, find the path with the maximum probability of success to go from&nbsp;<code>start</code>&nbsp;to&nbsp;<code>end</code>&nbsp;and return its success probability.</p>

<p>If there is no path from&nbsp;<code>start</code>&nbsp;to&nbsp;<code>end</code>, <strong>return&nbsp;0</strong>. Your answer will be accepted if it differs from the correct answer by at most <strong>1e-5</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/09/20/1558_ex1.png" style="width: 187px; height: 186px;"></strong></p>

<pre><strong>Input:</strong> n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
<strong>Output:</strong> 0.25000
<strong>Explanation:</strong>&nbsp;There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/09/20/1558_ex2.png" style="width: 189px; height: 186px;"></strong></p>

<pre><strong>Input:</strong> n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
<strong>Output:</strong> 0.30000
</pre>

<p><strong>Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/09/20/1558_ex3.png" style="width: 215px; height: 191px;"></strong></p>

<pre><strong>Input:</strong> n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
<strong>Output:</strong> 0.00000
<strong>Explanation:</strong>&nbsp;There is no path between 0 and 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10^4</code></li>
	<li><code>0 &lt;= start, end &lt; n</code></li>
	<li><code>start != end</code></li>
	<li><code>0 &lt;= a, b &lt; n</code></li>
	<li><code>a != b</code></li>
	<li><code>0 &lt;= succProb.length == edges.length &lt;= 2*10^4</code></li>
	<li><code>0 &lt;= succProb[i] &lt;= 1</code></li>
	<li>There is at most one edge between every two nodes.</li>
</ul>

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Graph](https://leetcode.com/tag/graph/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Shortest Path](https://leetcode.com/tag/shortest-path/)

**Similar Questions**:
* [Number of Ways to Arrive at Destination (Medium)](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/)

## Solution 1. Dijkstra

Direct application of Dijkstra algorithm except that usually the cost is the smaller the better, but in this problem the probability is the greater the better.

```cpp
// OJ: https://leetcode.com/problems/path-with-maximum-probability/
// Author: github.com/lzl124631x
// Time: O(ElogE)
// Space: O(E)
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& E, vector<double>& P, int start, int end) {
        vector<vector<pair<int, double>>> G(n);
        for (int i = 0; i < E.size(); ++i) {
            int u = E[i][0], v = E[i][1];
            G[u].emplace_back(v, P[i]);
            G[v].emplace_back(u, P[i]);
        }
        priority_queue<pair<double, int>> pq;
        pq.emplace(1, start);
        vector<double> dist(n);
        dist[start] = 1;
        while (pq.size()) {
            auto [p, u] = pq.top();
            pq.pop();
            if (p < dist[u]) continue;
            if (u == end) return p;
            for (auto &[v, w] : G[u]) {
                if (dist[v] >= p * w) continue;
                dist[v] = p * w;
                pq.emplace(dist[v], v);
            }
        }
        return 0;
    }
};
```

Or use `multiset`


```cpp
// OJ: https://leetcode.com/problems/path-with-maximum-probability/
// Author: github.com/lzl124631x
// Time: O(ElogE)
// Space: O(E)
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> G(n);
        for (int i = 0; i < edges.size(); ++i) {
            auto &e = edges[i];
            G[e[0]].emplace_back(e[1], succProb[i]);
            G[e[1]].emplace_back(e[0], succProb[i]);
        }
        multiset<pair<double, int>> s; // prob, index
        unordered_map<int, double> m;
        s.emplace(1, start);
        while (s.size()) {
            auto p = *s.rbegin();
            s.erase(prev(s.end()));
            int u = p.second;
            if (m.count(u)) continue;
            m[u] = p.first;
            if (u == end) return m[u];
            for (auto &[v, w] : G[u]) s.emplace(w * m[u], v);
        }
        return 0;
    }
};
```