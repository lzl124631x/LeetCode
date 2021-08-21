# [1976. Number of Ways to Arrive at Destination (Medium)](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/)

<p>You are in a city that consists of <code>n</code> intersections numbered from <code>0</code> to <code>n - 1</code> with <strong>bi-directional</strong> roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.</p>

<p>You are given an integer <code>n</code> and a 2D integer array <code>roads</code> where <code>roads[i] = [u<sub>i</sub>, v<sub>i</sub>, time<sub>i</sub>]</code> means that there is a road between intersections <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> that takes <code>time<sub>i</sub></code> minutes to travel. You want to know in how many ways you can travel from intersection <code>0</code> to intersection <code>n - 1</code> in the <strong>shortest amount of time</strong>.</p>

<p>Return <em>the <strong>number of ways</strong> you can arrive at your destination in the <strong>shortest amount of time</strong></em>. Since the answer may be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/17/graph2.png" style="width: 235px; height: 381px;">
<pre><strong>Input:</strong> n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2, roads = [[1,0,10]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>n - 1 &lt;= roads.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>roads[i].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>1 &lt;= time<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>u<sub>i </sub>!= v<sub>i</sub></code></li>
	<li>There is at most one road connecting any two intersections.</li>
	<li>You can reach any intersection from any other intersection.</li>
</ul>


**Similar Questions**:
* [All Paths From Source to Target (Medium)](https://leetcode.com/problems/all-paths-from-source-to-target/)
* [Path with Maximum Probability (Medium)](https://leetcode.com/problems/path-with-maximum-probability/)

## Solution 1. Dijkstra

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
// Author: github.com/lzl124631x
// Time: O(ElogE)
// Space: O(V + E)
class Solution {
    typedef pair<long, long> ipair;
public:
    int countPaths(int n, vector<vector<int>>& A) {
        vector<vector<pair<long, long>>> G(n);
        long mod = 1e9 + 7;
        for (auto &e : A) {
            long u = e[0], v = e[1], t = e[2];
            G[u].emplace_back(v, t);
            G[v].emplace_back(u, t);
        }
        priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
        vector<long> dist(n, LONG_MAX), cnt(n);
        dist[n-1] = 0;
        cnt[n-1] = 1;
        pq.emplace(0, n - 1);
        while (pq.size()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (cost > dist[u]) continue;
            for (auto &[v, t] : G[u]) {
                long c = dist[u] + t;
                if (dist[v] > c) {
                    dist[v] = c;
                    cnt[v] = cnt[u];
                    pq.emplace(dist[v], v);
                } else if (dist[v] == c) cnt[v] = (cnt[v] + cnt[u]) % mod;
            }
        }
        return cnt[0];
    }
};
```