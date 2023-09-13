# [1928. Minimum Cost to Reach Destination in Time (Hard)](https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/)

<p>There is a country of <code>n</code> cities numbered from <code>0</code> to <code>n - 1</code> where <strong>all the cities are connected</strong> by bi-directional roads. The roads are represented as a 2D integer array <code>edges</code> where <code>edges[i] = [x<sub>i</sub>, y<sub>i</sub>, time<sub>i</sub>]</code> denotes a road between cities <code>x<sub>i</sub></code> and <code>y<sub>i</sub></code> that takes <code>time<sub>i</sub></code> minutes to travel. There may be multiple roads of differing travel times connecting the same two cities, but no road connects a city to itself.</p>

<p>Each time you pass through a city, you must pay a passing fee. This is represented as a <strong>0-indexed</strong> integer array <code>passingFees</code> of length <code>n</code> where <code>passingFees[j]</code> is the amount of dollars you must pay when you pass through city <code>j</code>.</p>

<p>In the beginning, you are at city <code>0</code> and want to reach city <code>n - 1</code> in <code>maxTime</code><strong> minutes or less</strong>. The <strong>cost</strong> of your journey is the <strong>summation of passing fees</strong> for each city that you passed through at some moment of your journey (<strong>including</strong> the source and destination cities).</p>

<p>Given <code>maxTime</code>, <code>edges</code>, and <code>passingFees</code>, return <em>the <strong>minimum cost</strong> to complete your journey, or </em><code>-1</code><em> if you cannot complete it within </em><code>maxTime</code><em> minutes</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/06/04/leetgraph1-1.png" style="width: 371px; height: 171px;"></p>

<pre><strong>Input:</strong> maxTime = 30, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
<strong>Output:</strong> 11
<strong>Explanation:</strong> The path to take is 0 -&gt; 1 -&gt; 2 -&gt; 5, which takes 30 minutes and has $11 worth of passing fees.
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2021/06/04/copy-of-leetgraph1-1.png" style="width: 371px; height: 171px;"></strong></p>

<pre><strong>Input:</strong> maxTime = 29, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
<strong>Output:</strong> 48
<strong>Explanation:</strong> The path to take is 0 -&gt; 3 -&gt; 4 -&gt; 5, which takes 26 minutes and has $48 worth of passing fees.
You cannot take path 0 -&gt; 1 -&gt; 2 -&gt; 5 since it would take too long.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> maxTime = 25, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no way to reach city 5 from city 0 within 25 minutes.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= maxTime &lt;= 1000</code></li>
	<li><code>n == passingFees.length</code></li>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>n - 1 &lt;= edges.length &lt;= 1000</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>1 &lt;= time<sub>i</sub> &lt;= 1000</code></li>
	<li><code>1 &lt;= passingFees[j] &lt;= 1000</code>&nbsp;</li>
	<li>The graph may contain multiple edges between two nodes.</li>
	<li>The graph does not contain self loops.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Dijkstra

**Intuition**: BFS the graph in a way that we expand in the direction with the shortest time, and we log the smallest cost to a node at the same time. If the time already exceeds the `maxTime`, we stop the BFS.

**Algorithm**:

We can use Dijkstra for this greedy BFS. We use a min heap to keep track the expandable nodes with the shortest time taken. Each expandable nodes are represented as `(node, time, cost)` in the min heap.

We keep track of `minCost[u]` and `minTime[u]` which are the minimum cost/time to reach node `u`, respectively.

For a given node `(u, time, cost)`, we try expanding to each of `u`'s neighbor node `v`.

If the new time is greater than `maxTime`, we should skip it, i.e. `time + edge[u][v] > maxTime`

Otherwise, we expand in the following two cases:
1. The new cost reaching `v` is smaller than before, i.e. `cost + fee[v] < minCost[v]`.
2. The time taken to reach `v` is smaller than before, i.e. `time + edge[u][v] < minTime[v]`.

In the end, we return `minCost[N - 1]`.

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/
// Author: github.com/lzl124631x
// Time: O(ElogE)
// Space: O(V + E)
class Solution {
    typedef array<int, 3> Node; // node, time, cost
public:
    int minCost(int maxTime, vector<vector<int>>& E, vector<int>& F) {
        int N = F.size();
        vector<unordered_map<int, int>> G(N);
        vector<int> cost(N, INT_MAX), minTime(N, INT_MAX);
        for (auto &e : E) {
            int u = e[0], v = e[1], t = e[2];
            if (G[u].count(v)) { // For duplicated edges, we just need to keep track of the edge with smallest time.
                G[u][v] = min(G[u][v], t);
                G[v][u] = min(G[v][u], t);
            } else {
                G[u][v] = t;
                G[v][u] = t;
            }
        }
        auto cmp = [](auto &a, auto &b) { return a[1] > b[1]; }; // min-heap: Heap top is the node with the smallest time to reach
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        pq.push({0, 0, F[0]}); // we start from node `0` whose time is 0 and cost is fee[0]
        cost[0] = F[0];
        minTime[0] = 0;
        while (pq.size()) {
            auto [u, time, c] = pq.top();
            pq.pop();
            for (auto &[v, t] : G[u]) {
                int nt = time + t, nc = c + F[v];
                if (nt > maxTime) continue; // if time is out of range, skip
                if (nc < cost[v]) { // less cost
                    cost[v] = nc;
                    minTime[v] = min(minTime[v], nt);
                    pq.push({v, nt, nc});
                } else if (nt < minTime[v]) { // less time
                    minTime[v] = nt;
                    pq.push({v, nt, nc});
                }
            }
        }
        return cost[N - 1] == INT_MAX ? -1 : cost[N - 1];
    }
};
```

## Solution 2. Dijkstra

We change the min-heap to have the nodes with the smallest cost at the top.

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/
// Author: github.com/lzl124631x
// Time: O(ElogE)
// Space: O(V + E)
class Solution {
    typedef array<int, 3> Node; // node, time, cost
public:
    int minCost(int maxTime, vector<vector<int>>& E, vector<int>& F) {
        int N = F.size();
        vector<unordered_map<int, int>> G(N);
        vector<int> minTime(N, maxTime + 1);
        for (auto &e : E) {
            int u = e[0], v = e[1], t = e[2];
            if (G[u].count(v)) { // For duplicated edges, we just need to keep track of the edge with smallest time.
                G[u][v] = G[v][u] = min(G[u][v], t);
            } else {
                G[u][v] = G[v][u] = t;
            }
        }
        auto cmp = [](auto &a, auto &b) { return a[2] > b[2]; }; // min-heap: Heap top is the node with the smallest cost to reach
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        pq.push({0, 0, F[0]});
        minTime[0] = 0;
        while (pq.size()) {
            auto [u, time, c] = pq.top();
            pq.pop();
            if (u == N - 1) return c;
            for (auto &[v, t] : G[u]) {
                int nt = time + t, nc = c + F[v];
                if (nt < minTime[v]) {
                    minTime[v] = nt;
                    pq.push({v, nt, nc});
                }
            }
        }
        return -1;
    }
};
```