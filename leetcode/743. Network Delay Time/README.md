# [743. Network Delay Time (Medium)](https://leetcode.com/problems/network-delay-time/)

<p>There are <code>N</code> network nodes, labelled <code>1</code> to <code>N</code>.</p>

<p>Given <code>times</code>, a list of travel times as <b>directed</b> edges <code>times[i] = (u, v, w)</code>, where <code>u</code> is the source node, <code>v</code> is the target node, and <code>w</code> is the time it takes for a signal to travel from source to target.</p>

<p>Now, we send a signal from a certain node <code>K</code>. How long will it take for all nodes to receive the signal? If it is impossible, return <code>-1</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png" style="width: 200px; height: 220px;"></p>

<pre><strong>Input: </strong>times = <span id="example-input-1-1">[[2,1,1],[2,3,1],[3,4,1]]</span>, N = <span id="example-input-1-2">4</span>, K = <span id="example-input-1-3">2</span>
<strong>Output: </strong><span id="example-output-1">2</span>
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li><code>N</code> will be in the range <code>[1, 100]</code>.</li>
	<li><code>K</code> will be in the range <code>[1, N]</code>.</li>
	<li>The length of <code>times</code> will be in the range <code>[1, 6000]</code>.</li>
	<li>All edges <code>times[i] = (u, v, w)</code> will have <code>1 &lt;= u, v &lt;= N</code> and <code>0 &lt;= w &lt;= 100</code>.</li>
</ol>


**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1. Dijkstra

```cpp
// OJ: https://leetcode.com/problems/network-delay-time/
// Author: github.com/lzl124631x
// Time: O(E + VlogV)
// Space: O(E)
class Solution {
    typedef pair<int, int> iPair;
    typedef unordered_map<int, vector<iPair>> Graph;
    vector<int> dijkstra(Graph &graph, int N, int source) {
        priority_queue<iPair, vector<iPair>, greater<>> pq;
        vector<int> dist(N, INT_MAX);
        pq.emplace(0, source);
        dist[source] = 0;
        while (pq.size()) {
            auto [w, u] = pq.top();
            pq.pop();
            if (w > dist[u]) continue;
            for (auto &[v, c] : graph[u]) {
                if (dist[v] > w + c) {
                    dist[v] = w + c;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        Graph graph;
        for (auto e : times) graph[e[0] - 1].emplace_back(e[1] - 1, e[2]);
        auto dist = dijkstra(graph, N, K - 1);
        int mx = *max_element(begin(dist), end(dist)); 
        return mx == INT_MAX ? -1 : mx;
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
    vector<int> bellmanFord(vector<vector<int>>& edges, int V, int src) {
        vector<int> dist(V, INT_MAX);
        dist[src - 1] = 0;
        for (int i = 1; i < V; ++i) {
            for (auto &e : edges) {
                int u = e[0] - 1, v = e[1] - 1, w = e[2];
                if (dist[u] == INT_MAX) continue;
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
        return dist;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        auto dist = bellmanFord(times, N, K);
        int ans = *max_element(dist.begin(), dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
```