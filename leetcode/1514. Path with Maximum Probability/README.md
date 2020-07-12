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

**Related Topics**:  
[Graph](https://leetcode.com/tag/graph/)

## Solution 1. Dijkstra

Direct application of Dijkstra algorithm except that usually the cost is the smaller the better, but in this problem the probability is the greater the better.

```cpp
// OJ: https://leetcode.com/problems/path-with-maximum-probability/
// Author: github.com/lzl124631x
// Time: O(E+VlogV)
// Space: O(E)
class Solution {
    typedef pair<double, int> P; // possibility, index
public:
    double maxProbability(int n, vector<vector<int>>& E, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> G(n);
        for (int i = 0; i < E.size(); ++i) {
            auto &e = E[i];
            G[e[0]].emplace_back(e[1], succProb[i]);
            G[e[1]].emplace_back(e[0], succProb[i]);
        }
        priority_queue<P, vector<P>, less<P>> q;
        vector<double> d(n, 0);
        q.emplace(1, start);
        d[start] = 1;
        while (q.size()) {
            auto p = q.top();
            int u = p.second;
            q.pop();
            if (p.first < d[u]) continue; // this line is very important, otherwise you might get TLE
            for (auto &nei : G[u]) {
                double v = nei.first, w = nei.second;
                if (d[v] < d[u] * w) {
                    d[v] = d[u] * w;
                    q.emplace(d[v], v);
                }
            }
        }
        return d[end];
    }
};
```