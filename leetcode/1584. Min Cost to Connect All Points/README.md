# [1584. Min Cost to Connect All Points (Medium)](https://leetcode.com/problems/min-cost-to-connect-all-points/)

<p>You are given an array&nbsp;<code>points</code>&nbsp;representing integer coordinates of some points on a 2D-plane, where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>.</p>

<p>The cost of connecting two points <code>[x<sub>i</sub>, y<sub>i</sub>]</code> and <code>[x<sub>j</sub>, y<sub>j</sub>]</code> is the <strong>manhattan distance</strong> between them:&nbsp;<code>|x<sub>i</sub> - x<sub>j</sub>| + |y<sub>i</sub> - y<sub>j</sub>|</code>, where <code>|val|</code> denotes the absolute value of&nbsp;<code>val</code>.</p>

<p>Return&nbsp;<em>the minimum cost to make all points connected.</em> All points are connected if there is <strong>exactly one</strong> simple path between any two points.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/08/26/d.png" style="width: 214px; height: 268px;"></p>

<pre><strong>Input:</strong> points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
<strong>Output:</strong> 20
<strong>Explanation:
</strong><img alt="" src="https://assets.leetcode.com/uploads/2020/08/26/c.png" style="width: 214px; height: 268px;">
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> points = [[3,12],[-2,5],[-4,1]]
<strong>Output:</strong> 18
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> points = [[0,0],[1,1],[1,0],[-1,1]]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> points = [[-1000000,-1000000],[1000000,1000000]]
<strong>Output:</strong> 4000000
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> points = [[0,0]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 1000</code></li>
	<li><code>-10<sup>6</sup>&nbsp;&lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li>All pairs <code>(x<sub>i</sub>, y<sub>i</sub>)</code> are distinct.</li>
</ul>


**Related Topics**:  
[Union Find](https://leetcode.com/tag/union-find/)

## Solution 1. Kruskal

The run time is too restrict. If you sort the edges then use Kruskal you will get TLE. The time complexity is `O(N^2 * log(N^2))`.

We have to use min heap instead so that the time complexity is `O(K * log(N^2))` where `K` is the number of edges we need to pull to complete the tree. It's much smaller than `N^2` on average.

```cpp
// OJ: https://leetcode.com/problems/min-cost-to-connect-all-points/
// Author: github.com/lzl124631x
// Time: O(K * log(N^2))
// Space: O(N^2)
// Ref: https://leetcode.com/problems/min-cost-to-connect-all-points/discuss/843940/C%2B%2B-Minimum-Spanning-Tree-(Kruskal)
class UnionFind {
    vector<int> id;
    int size;
public:
    UnionFind(int N) : id(N), size(N) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        id[p] = q;
        --size;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    int getSize() { return size; }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& A) {
        int N = A.size(), ans = 0;
        vector<array<int, 3>> E;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) E.push_back({ abs(A[i][0] - A[j][0]) + abs(A[i][1] - A[j][1]), i, j });
        }
        make_heap(begin(E), end(E), greater<array<int, 3>>());
        UnionFind uf(N);
        while (uf.getSize() > 1) {
            pop_heap(begin(E), end(E), greater<array<int, 3>>());
            auto [w, u, v] = E.back();
            E.pop_back();
            if (uf.connected(u, v)) continue;
            uf.connect(u, v);
            ans += w;
        } 
        return ans;
    }
};
```

We can also directly use `priority_queue`.

```cpp
// OJ: https://leetcode.com/problems/min-cost-to-connect-all-points/
// Author: github.com/lzl124631x
// Time: O(K * log(N^2))
// Space: O(N^2)
class UnionFind {
    vector<int> id;
    int size;
public:
    UnionFind(int N) : id(N), size(N) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        id[p] = q;
        --size;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    int getSize() { return size; }
};
class Solution {
    typedef array<int, 3> Edge;
public:
    int minCostConnectPoints(vector<vector<int>>& A) {
        int N = A.size(), ans = 0;
        priority_queue<Edge, vector<Edge>, greater<Edge>> q;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) q.push({ abs(A[i][0] - A[j][0]) + abs(A[i][1] - A[j][1]), i, j });
        }
        UnionFind uf(N);
        while (uf.getSize() > 1) {
            auto [w, u, v] = q.top();
            q.pop();
            if (uf.connected(u, v)) continue;
            uf.connect(u, v);
            ans += w;
        } 
        return ans;
    }
};
```

## Solution 2. Prim

1. Start from a random node (we use `0` here), add it to the minimum spanning tree (MST).
1. From all the edges connecting nodes in the MST and those outside of the MST, find the edge with the mimimal cost, and add the corresponding node to the MST.
1. Repeat Step 2 until all the nodes are added into the MST.

```cpp
// OJ: https://leetcode.com/problems/min-cost-to-connect-all-points/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
// Ref: https://leetcode.com/problems/min-cost-to-connect-all-points/discuss/843921/PythonGolang-Just-add-points-greedily
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& A) {
        int N = A.size(), ans = 0, cur = 0;
        vector<int> dist(N, INT_MAX), seen(N);
        for (int i = 0; i < N - 1; ++i) {
            int x = A[cur][0], y = A[cur][1];
            seen[cur] = 1;
            for (int j = 0; j < N; ++j) {
                if (seen[j]) continue;
                dist[j] = min(dist[j], abs(A[j][0] - x) + abs(A[j][1] - y));
            }
            cur = min_element(begin(dist), end(dist)) - begin(dist);
            ans += dist[cur];
            dist[cur] = INT_MAX;
        }
        return ans;
    }
};
```