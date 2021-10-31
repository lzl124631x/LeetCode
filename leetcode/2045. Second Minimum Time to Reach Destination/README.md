# [2045. Second Minimum Time to Reach Destination (Hard)](https://leetcode.com/problems/second-minimum-time-to-reach-destination/)

<p>A city is represented as a <strong>bi-directional connected</strong> graph with <code>n</code> vertices where each vertex is labeled from <code>1</code> to <code>n</code> (<strong>inclusive</strong>). The edges in the graph are represented as a 2D integer array <code>edges</code>, where each <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> denotes a bi-directional edge between vertex <code>u<sub>i</sub></code> and vertex <code>v<sub>i</sub></code>. Every vertex pair is connected by <strong>at most one</strong> edge, and no vertex has an edge to itself. The time taken to traverse any edge is <code>time</code> minutes.</p>

<p>Each vertex has a traffic signal which changes its color from <strong>green</strong> to <strong>red</strong> and vice versa every&nbsp;<code>change</code> minutes. All signals change <strong>at the same time</strong>. You can enter a vertex at <strong>any time</strong>, but can leave a vertex <strong>only when the signal is green</strong>. You <strong>cannot wait </strong>at a vertex if the signal is <strong>green</strong>.</p>

<p>The <strong>second minimum value</strong> is defined as the smallest value<strong> strictly larger </strong>than the minimum value.</p>

<ul>
	<li>For example the second minimum value of <code>[2, 3, 4]</code> is <code>3</code>, and the second minimum value of <code>[2, 2, 4]</code> is <code>4</code>.</li>
</ul>

<p>Given <code>n</code>, <code>edges</code>, <code>time</code>, and <code>change</code>, return <em>the <strong>second minimum time</strong> it will take to go from vertex </em><code>1</code><em> to vertex </em><code>n</code>.</p>

<p><strong>Notes:</strong></p>

<ul>
	<li>You can go through any vertex <strong>any</strong> number of times, <strong>including</strong> <code>1</code> and <code>n</code>.</li>
	<li>You can assume that when the journey <strong>starts</strong>, all signals have just turned <strong>green</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/29/e1.png" style="width: 200px; height: 250px;">        <img alt="" src="https://assets.leetcode.com/uploads/2021/09/29/e2.png" style="width: 200px; height: 250px;">
<pre><strong>Input:</strong> n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
<strong>Output:</strong> 13
<strong>Explanation:</strong>
The figure on the left shows the given graph.
The blue path in the figure on the right is the minimum time path.
The time taken is:
- Start at 1, time elapsed=0
- 1 -&gt; 4: 3 minutes, time elapsed=3
- 4 -&gt; 5: 3 minutes, time elapsed=6
Hence the minimum time needed is 6 minutes.

The red path shows the path to get the second minimum time.
- Start at 1, time elapsed=0
- 1 -&gt; 3: 3 minutes, time elapsed=3
- 3 -&gt; 4: 3 minutes, time elapsed=6
- Wait at 4 for 4 minutes, time elapsed=10
- 4 -&gt; 5: 3 minutes, time elapsed=13
Hence the second minimum time is 13 minutes.      
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/09/29/eg2.png" style="width: 225px; height: 50px;">
<pre><strong>Input:</strong> n = 2, edges = [[1,2]], time = 3, change = 2
<strong>Output:</strong> 11
<strong>Explanation:</strong>
The minimum time path is 1 -&gt; 2 with time = 3 minutes.
The second minimum time path is 1 -&gt; 2 -&gt; 1 -&gt; 2 with time = 11 minutes.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>n - 1 &lt;= edges.length &lt;= min(2 * 10<sup>4</sup>, n * (n - 1) / 2)</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li>There are no duplicate edges.</li>
	<li>Each vertex can be reached directly or indirectly from every other vertex.</li>
	<li><code>1 &lt;= time, change &lt;= 10<sup>3</sup></code></li>
</ul>


**Similar Questions**:
* [Network Delay Time (Medium)](https://leetcode.com/problems/network-delay-time/)
* [Find the City With the Smallest Number of Neighbors at a Threshold Distance (Medium)](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/)
* [Number of Ways to Arrive at Destination (Medium)](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/)


## Solution 1. BFS

**Intuition**: If the shortest path from `1` to `n` is of length `L`, find whether there is a path of length `L + 1` by taking a detour. There is always a path of length `L + 2` (by going back-and-forth).

```cpp
// OJ: https://leetcode.com/problems/second-minimum-time-to-reach-destination/
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N + E)
// Ref: https://leetcode.com/problems/second-minimum-time-to-reach-destination/discuss/1525165/C%2B%2B-Two-BFS-with-detailed-explanation
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& E, int time, int change) {
        vector<vector<int>> G(n);
        for (auto &e : E) {
            int u = e[0] - 1, v = e[1] - 1;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> dist(n, INT_MAX);
        dist[n - 1] = 0;
        queue<int> q{{n - 1}};
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                if (dist[v] != INT_MAX) continue;
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
        int len = dist[0] + 2; // Try to find a path of length `dist[0] + 1`
        q.push(0);
        bool found = false;
        while (q.size() && !found) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                if (dist[v] == dist[u]) { // u and v are at the same layer of the shortest path, so dist[u] can be 1 + dist[u] by going to v first then u.
                    len--;
                    found = true;
                    break;
                } else if (dist[v] == dist[u] - 1) q.push(v); // push the nodes on the next layer of the shortest path
            }
        }
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            ans += time;
            if (i != len - 1 && ans / change % 2) ans = (ans / change + 1) * change;
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/second-minimum-time-to-reach-destination/
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N + E)
// Ref: https://leetcode.com/problems/second-minimum-time-to-reach-destination/discuss/1525154/No-Dijkstra%3A-(n-%2B-1)-or-(n-%2B-2)
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& E, int time, int change) {
        auto getTime = [&](int step) {
            int ans = 0;
            for (int i = 0; i < step; ++i) {
                ans += time;
                if (i != step - 1 && ans / change % 2) ans = (ans / change + 1) * change;
            }
            return ans;
        };
        vector<vector<int>> G(n);
        for (auto &e : E) {
            int u = e[0] - 1, v = e[1] - 1;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> dist(n, 10001);
        queue<int> q{{0}};
        int step = 0;
        while (q.size() && step <= dist[n - 1] + 1) {
            int cnt = q.size();
            while (cnt--) {
                int u = q.front();
                q.pop();
                if (step == dist[u] || step > dist[u] + 1) continue; // Only visit node `u` if it haven't been visited or this visit takes only one more step than last time.
                dist[u] = min(dist[u], step);
                if (u == n - 1 && step == dist[n - 1] + 1) return getTime(step);
                for (int v : G[u]) q.push(v);
            }
            ++step;
        }
        return getTime(dist[n - 1] + 2);
    }
};
```