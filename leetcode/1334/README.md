# [1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance (Medium)](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/)

<p>There are <code>n</code> cities numbered from <code>0</code> to <code>n-1</code>. Given the array <code>edges</code>&nbsp;where <code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>, weight<sub>i</sub>]</code> represents a bidirectional and weighted edge between cities <code>from<sub>i</sub></code>&nbsp;and <code>to<sub>i</sub></code>, and given the integer <code>distanceThreshold</code>.</p>

<p>Return the city with the smallest number<strong> </strong>of&nbsp;cities that are reachable through some path and whose distance is <strong>at most</strong> <code>distanceThreshold</code>, If there are multiple such cities, return the city with the greatest number.</p>

<p>Notice that the distance of a path connecting cities <em><strong>i</strong></em> and <em><strong>j</strong></em> is equal to the sum of the edges' weights along that path.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/01/16/find_the_city_01.png" style="width: 300px; height: 225px;"></p>

<pre><strong>Input:</strong> n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
<strong>Output:</strong> 3
<strong>Explanation: </strong>The figure above describes the graph.&nbsp;
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -&gt; [City 1, City 2]&nbsp;
City 1 -&gt; [City 0, City 2, City 3]&nbsp;
City 2 -&gt; [City 0, City 1, City 3]&nbsp;
City 3 -&gt; [City 1, City 2]&nbsp;
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/01/16/find_the_city_02.png" style="width: 300px; height: 225px;"></strong></p>

<pre><strong>Input:</strong> n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
<strong>Output:</strong> 0
<strong>Explanation: </strong>The figure above describes the graph.&nbsp;
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -&gt; [City 1]&nbsp;
City 1 -&gt; [City 0, City 4]&nbsp;
City 2 -&gt; [City 3, City 4]&nbsp;
City 3 -&gt; [City 2, City 4]
City 4 -&gt; [City 1, City 2, City 3]&nbsp;
The city 0 has 1 neighboring city at a distanceThreshold = 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= edges.length &lt;= n * (n - 1) / 2</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= from<sub>i</sub> &lt; to<sub>i</sub> &lt; n</code></li>
	<li><code>1 &lt;= weight<sub>i</sub>,&nbsp;distanceThreshold &lt;= 10^4</code></li>
	<li>All pairs <code>(from<sub>i</sub>, to<sub>i</sub>)</code> are distinct.</li>
</ul>

**Related Topics**:  
[Graph](https://leetcode.com/tag/graph/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// Author: github.com/lzl124631x
// Time: O(V * (E + VlogV))
// Space: O(E)
class Solution {
    typedef pair<int, int> iPair; 
    unordered_map<int, vector<iPair>> graph;
    int th, N, minNum = INT_MAX;
    int dijkstra(int i) {
        priority_queue<iPair, vector<iPair>, greater<iPair>> q;
        vector<int> dist(N, INT_MAX);
        q.push(make_pair(0, i));
        dist[i] = 0;
        while (q.size()) {
            int u = q.top().second;
            q.pop();
            for (auto ne : graph[u]) {
                int v = ne.first;
                int w = ne.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.push(make_pair(dist[v], v));
                }
            }
        }
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            if (j != i && dist[j] <= th) ++cnt;
        }
        return cnt;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        th = distanceThreshold;
        N = n;
        for (auto e : edges) {
            m[e[0]].push_back(make_pair(e[1], e[2]));
            m[e[1]].push_back(make_pair(e[0], e[2]));
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = dijkstra(i);
            if (cnt <= minNum) {
                minNum = cnt;
                ans = i;
            }
        }
        return ans;
    }
};
```

## Solution 2. Floyd-Warshall

```cpp
// OJ: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& E, int k) {
        vector<vector<int>> d(n, vector<int>(n, (int) 1e6));
        for (int i = 0; i < n; ++i) d[i][i] = 0;
        for (auto &e : E) {
            d[e[0]][e[1]] = d[e[1]][e[0]] = e[2];
        }
        for (int i = 0; i < n; ++i) {
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    d[u][v] = min(d[u][v], d[u][i] + d[i][v]);
                }
            }
        }
        int ans = 0, minCnt = n;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (d[i][j] <= k) ++cnt;
            }
            if (cnt <= minCnt) {
                minCnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};
```