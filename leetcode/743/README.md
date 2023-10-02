# [743. Network Delay Time (Medium)](https://leetcode.com/problems/network-delay-time/)

<p>You are given a network of <code>n</code> nodes, labeled from <code>1</code> to <code>n</code>. You are also given <code>times</code>, a list of travel times as directed edges <code>times[i] = (u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>)</code>, where <code>u<sub>i</sub></code> is the source node, <code>v<sub>i</sub></code> is the target node, and <code>w<sub>i</sub></code> is the time it takes for a signal to travel from source to target.</p>

<p>We will send a signal from a given node <code>k</code>. Return the time it takes for all the <code>n</code> nodes to receive the signal. If it is impossible for all the <code>n</code> nodes to receive the signal, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png" style="width: 217px; height: 239px;">
<pre><strong>Input:</strong> times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
<strong>Output:</strong> 2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> times = [[1,2,1]], n = 2, k = 1
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> times = [[1,2,1]], n = 2, k = 2
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= times.length &lt;= 6000</code></li>
	<li><code>times[i].length == 3</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>0 &lt;= w<sub>i</sub> &lt;= 100</code></li>
	<li>All the pairs <code>(u<sub>i</sub>, v<sub>i</sub>)</code> are <strong>unique</strong>. (i.e., no multiple edges.)</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Shortest Path](https://leetcode.com/tag/shortest-path/)

**Similar Questions**:
* [The Time When the Network Becomes Idle (Medium)](https://leetcode.com/problems/the-time-when-the-network-becomes-idle/)
* [Second Minimum Time to Reach Destination (Hard)](https://leetcode.com/problems/second-minimum-time-to-reach-destination/)

## Solution 1. Dijkstra

```cpp
// OJ: https://leetcode.com/problems/network-delay-time/
// Author: github.com/lzl124631x
// Time: O(E + VlogV)
// Space: O(E)
class Solution {
    typedef pair<int, int> PII;
public:
    int networkDelayTime(vector<vector<int>>& E, int n, int k) {
        vector<vector<PII>> G(n);
        for (auto &e : E) G[e[0] - 1].emplace_back(e[1] - 1, e[2]);
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;
        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.emplace(0, k - 1);
        while (pq.size()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (dist[u] > cost) continue; 
            for (auto &[v, w] : G[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        int ans = *max_element(begin(dist), end(dist));
        return ans == INT_MAX ? -1 : ans;
    }
};
```

## Solution 2. Bellman-Ford

```cpp
// OJ: https://leetcode.com/problems/network-delay-time/
// Author: github.com/lzl124631x
// Time: O(VE)
// Space: O(V)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& E, int n, int k) {
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;
        for (int i = 1; i < n; ++i) {
            for (auto &e : E) {
                int u = e[0] - 1, v = e[1] - 1, w = e[2];
                if (dist[u] != INT_MAX) dist[v] = min(dist[v], dist[u] + w);
            }
        }
        int ans = *max_element(begin(dist), end(dist));
        return ans == INT_MAX ? -1 : ans;
    }
};
```