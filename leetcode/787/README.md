# [787. Cheapest Flights Within K Stops (Medium)](https://leetcode.com/problems/cheapest-flights-within-k-stops/)

<p>There are <code>n</code> cities connected by&nbsp;<code>m</code> flights. Each flight starts from city&nbsp;<code>u</code> and arrives at&nbsp;<code>v</code> with a price <code>w</code>.</p>

<p>Now given all the cities and flights, together with starting city <code>src</code> and the destination&nbsp;<code>dst</code>, your task is to find the cheapest price from <code>src</code> to <code>dst</code> with up to <code>k</code> stops. If there is no such route, output <code>-1</code>.</p>

<pre><strong>Example 1:</strong>
<strong>Input:</strong> 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
<strong>Output:</strong> 200
<strong>Explanation:</strong> 
The graph looks like this:
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png" style="height:180px; width:246px">

The cheapest price from city <code>0</code> to city <code>2</code> with at most 1 stop costs 200, as marked red in the picture.</pre>

<pre><strong>Example 2:</strong>
<strong>Input:</strong> 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
<strong>Output:</strong> 500
<strong>Explanation:</strong> 
The graph looks like this:
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png" style="height:180px; width:246px">

The cheapest price from city <code>0</code> to city <code>2</code> with at most 0 stop costs 500, as marked blue in the picture.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of&nbsp;nodes&nbsp;<code>n</code> will be&nbsp;in range <code>[1, 100]</code>, with nodes labeled from <code>0</code> to <code>n</code><code> - 1</code>.</li>
	<li>The&nbsp;size of <code>flights</code> will be&nbsp;in range <code>[0, n * (n - 1) / 2]</code>.</li>
	<li>The format of each flight will be <code>(src, </code><code>dst</code><code>, price)</code>.</li>
	<li>The price of each flight will be in the range <code>[1, 10000]</code>.</li>
	<li><code>k</code> is in the range of <code>[0, n - 1]</code>.</li>
	<li>There&nbsp;will&nbsp;not&nbsp;be&nbsp;any&nbsp;duplicated&nbsp;flights or&nbsp;self&nbsp;cycles.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Heap](https://leetcode.com/tag/heap/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Maximum Vacation Days (Hard)](https://leetcode.com/problems/maximum-vacation-days/)

## Solution 1. Bellman ford

With `k` stops, the longest path has `k + 1` edges. So, using Bellman-ford algorithm, we should relax `k + 1` times.

The relaxation happens from layer to layer. This is to prevent using distance in layer `i` when relaxing from layer `i-1` to layer `i`.

```cpp
// OJ: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Author: github.com/lzl124631x
// Time: O(K * (N+ E))
// Space: O(N)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& A, int src, int dst, int K) {
        vector<int> dist(n, 1e8);
        dist[src] = 0;
        for (int i = 0; i <= K; ++i) {
            auto tmp = dist;
            for (auto &e : A) {
                int u = e[0], v = e[1], w = e[2];
                dist[v] = min(dist[v], tmp[u] + w);
            }
        }
        return dist[dst] == 1e8 ? -1 : dist[dst];
    }
};
```

## Solution 2. Dijkstra

```cpp
// OJ: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Author: github.com/lzl124631x
// Time: O(KElogE)
// Space: O(KN + E)
class Solution {
    typedef array<int, 3> item; // distance, cityId, # stops left
public:
    int findCheapestPrice(int n, vector<vector<int>>& E, int src, int dst, int k) {
        vector<vector<pair<int, int>>> G(n);
        for (auto &e : E) G[e[0]].emplace_back(e[1], e[2]);
        priority_queue<item, vector<item>, greater<>> pq;
        ++k;
        pq.push({0, src, k});
        vector<vector<int>> dist(k + 1, vector<int>(n, INT_MAX));
        for (int i = 0; i <= k; ++i) dist[i][src] = 0;
        while (pq.size()) {
            auto [cost, u, stop] = pq.top();
            pq.pop();
            if (cost > dist[stop][u]) continue;
            if (u == dst) return cost;
            if (stop == 0) continue;
            for (auto &[v, w] : G[u]) {
                if (dist[stop - 1][v] > cost + w) {
                    dist[stop - 1][v] = cost + w;
                    pq.push({dist[stop - 1][v], v, stop - 1});
                }
            }
        }
        return -1;
    }
};
```

## Solution 3. BFS

A plain BFS also works, but it doesn't prioritize low cost paths first so it might be less efficient.

```cpp
// OJ: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Author: github.com/lzl124631x
// Time: O(KE)
// Space: O(N + E)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& E, int src, int dst, int k) {
        vector<vector<pair<int, int>>> G(n);
        for (auto &e : E) G[e[0]].emplace_back(e[1], e[2]);
        queue<pair<int, int>> q; // cityId, cost
        q.emplace(src, 0);
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        int step = 0;
        while (step <= k) {
            int cnt = q.size();
            while (cnt--) {
                auto [u, cost] = q.front();
                q.pop();
                for (auto &[v, w] : G[u]) {
                    if (dist[v] > cost + w) { // Note that we shouldn't use `dist[u]` here. Because `dist[u]` might get updated using two jumps but the `cost` here corresponds to one jump.
                        dist[v] = cost + w;
                        q.emplace(v, dist[v]);
                    }
                }
            }
            ++step;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
```