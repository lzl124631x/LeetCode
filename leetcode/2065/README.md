# [2065. Maximum Path Quality of a Graph (Hard)](https://leetcode.com/problems/maximum-path-quality-of-a-graph/)

<p>There is an <strong>undirected</strong> graph with <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code> (<strong>inclusive</strong>). You are given a <strong>0-indexed</strong> integer array <code>values</code> where <code>values[i]</code> is the <strong>value </strong>of the <code>i<sup>th</sup></code> node. You are also given a <strong>0-indexed</strong> 2D integer array <code>edges</code>, where each <code>edges[j] = [u<sub>j</sub>, v<sub>j</sub>, time<sub>j</sub>]</code> indicates that there is an undirected edge between the nodes <code>u<sub>j</sub></code> and <code>v<sub>j</sub></code>,<sub> </sub>and it takes <code>time<sub>j</sub></code> seconds to travel between the two nodes. Finally, you are given an integer <code>maxTime</code>.</p>

<p>A <strong>valid</strong> <strong>path</strong> in the graph is any path that starts at node <code>0</code>, ends at node <code>0</code>, and takes <strong>at most</strong> <code>maxTime</code> seconds to complete. You may visit the same node multiple times. The <strong>quality</strong> of a valid path is the <strong>sum</strong> of the values of the <strong>unique nodes</strong> visited in the path (each node's value is added <strong>at most once</strong> to the sum).</p>

<p>Return <em>the <strong>maximum</strong> quality of a valid path</em>.</p>

<p><strong>Note:</strong> There are <strong>at most four</strong> edges connected to each node.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/19/ex1drawio.png" style="width: 269px; height: 170px;">
<pre><strong>Input:</strong> values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
<strong>Output:</strong> 75
<strong>Explanation:</strong>
One possible path is 0 -&gt; 1 -&gt; 0 -&gt; 3 -&gt; 0. The total time taken is 10 + 10 + 10 + 10 = 40 &lt;= 49.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 0 + 32 + 43 = 75.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/19/ex2drawio.png" style="width: 269px; height: 170px;">
<pre><strong>Input:</strong> values = [5,10,15,20], edges = [[0,1,10],[1,2,10],[0,3,10]], maxTime = 30
<strong>Output:</strong> 25
<strong>Explanation:</strong>
One possible path is 0 -&gt; 3 -&gt; 0. The total time taken is 10 + 10 = 20 &lt;= 30.
The nodes visited are 0 and 3, giving a maximal path quality of 5 + 20 = 25.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/19/ex31drawio.png" style="width: 236px; height: 170px;">
<pre><strong>Input:</strong> values = [1,2,3,4], edges = [[0,1,10],[1,2,11],[2,3,12],[1,3,13]], maxTime = 50
<strong>Output:</strong> 7
<strong>Explanation:</strong>
One possible path is 0 -&gt; 1 -&gt; 3 -&gt; 1 -&gt; 0. The total time taken is 10 + 13 + 13 + 10 = 46 &lt;= 50.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 1 + 2 + 4 = 7.</pre>

<p><strong>Example 4:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2021/10/21/ex4drawio.png" style="width: 270px; height: 71px;"></strong></p>

<pre><strong>Input:</strong> values = [0,1,2], edges = [[1,2,10]], maxTime = 10
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
The only path is 0. The total time taken is 0.
The only node visited is 0, giving a maximal path quality of 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == values.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= values[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 2000</code></li>
	<li><code>edges[j].length == 3 </code></li>
	<li><code>0 &lt;= u<sub>j </sub>&lt; v<sub>j</sub> &lt;= n - 1</code></li>
	<li><code>10 &lt;= time<sub>j</sub>, maxTime &lt;= 100</code></li>
	<li>All the pairs <code>[u<sub>j</sub>, v<sub>j</sub>]</code> are <strong>unique</strong>.</li>
	<li>There are <strong>at most four</strong> edges connected to each node.</li>
	<li>The graph may not be connected.</li>
</ul>


**Similar Questions**:
* [Cherry Pickup (Hard)](https://leetcode.com/problems/cherry-pickup/)
* [Minimum Cost to Reach Destination in Time (Hard)](https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/)

## Solution 1. DFS

Since `10 <= timej, maxTime <= 100`, the path at most have `10` edges. Since each node at most has `4` edges, the maximum number of possible paths is `4^10 ~= 1e6`, so a brute force DFS should work.

```cpp
// OJ: https://leetcode.com/problems/maximum-path-quality-of-a-graph/
// Author: github.com/lzl124631x
// Time: O(4^10)
// Space: O(V + E)
class Solution {
public:
    int maximalPathQuality(vector<int>& V, vector<vector<int>>& E, int maxTime) {
        int N = V.size();
        vector<vector<pair<int, int>>> G(N); // build graph
        for (auto &e : E) {
            int u = e[0], v = e[1], c = e[2];
            G[u].emplace_back(v, c);
            G[v].emplace_back(u, c);
        }
        vector<int> cnt(N); // `cnt[u]` is the number of times we've visted node `u` in the current path
        int ans = 0;
        function<void(int, int, int)> dfs = [&](int u, int val, int time) {
            if (cnt[u] == 0) val += V[u];
            cnt[u]++;
            if (u == 0) ans = max(ans, val); // Only update answer if the current node is `0`.
            for (auto &[v, c] : G[u]) {
                if (time + c > maxTime) continue; // if the current time + the edge time is greater than maxTime, skip
                dfs(v, val, time + c);
            }
            cnt[u]--;
        };
        dfs(0, 0, 0);
        return ans;
    }
};
```

Or we can optionally add Dijkstra to backtrack earlier.

```cpp
// OJ: https://leetcode.com/problems/maximum-path-quality-of-a-graph/
// Author: github.com/lzl124631x
// Time: O(ElogE + 4^10)
// Space: O(V + E)
class Solution {
    typedef array<int, 2> T;
public:
    int maximalPathQuality(vector<int>& V, vector<vector<int>>& E, int maxTime) {
        int N = V.size();
        vector<vector<array<int, 2>>> G(N); // build graph
        for (auto &e : E) {
            int u = e[0], v = e[1], c = e[2];
            G[u].push_back({v, c});
            G[v].push_back({u, c});
        }
        priority_queue<T, vector<T>, greater<T>> pq; // use Dijkstra to find the shortest distance from node 0 to all other nodes.
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;
        pq.push({0, 0});
        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto &[v, c] : G[u]) {
                if (dist[v] > dist[u] + c) {
                    dist[v] = dist[u] + c;
                    pq.push({dist[v], v});
                }
            }
        }
        vector<int> cnt(N); // `cnt[u]` is the number of times we've visted node `u` in the current path
        int ans = 0;
        function<void(int, int, int)> dfs = [&](int u, int val, int time) {
            if (cnt[u] == 0) val += V[u];
            cnt[u]++;
            if (u == 0) ans = max(ans, val); // Only update answer if the current node is `0`.
            for (auto &[v, c] : G[u]) {
                if (time + c + dist[v] > maxTime) continue; // if the current time + the edge time + dist[u] is greater than maxTime, skip
                dfs(v, val, time + c);
            }
            cnt[u]--;
        };
        dfs(0, 0, 0);
        return ans;
    }
};
```