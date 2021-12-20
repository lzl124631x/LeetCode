# [1135. Connecting Cities With Minimum Cost (Medium)](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)

<p>There are <code>n</code> cities labeled from <code>1</code> to <code>n</code>. You are given the integer <code>n</code> and an array <code>connections</code> where <code>connections[i] = [x<sub>i</sub>, y<sub>i</sub>, cost<sub>i</sub>]</code> indicates that the cost of connecting city <code>x<sub>i</sub></code> and city <code>y<sub>i</sub></code> (bidirectional connection) is <code>cost<sub>i</sub></code>.</p>

<p>Return <em>the minimum <strong>cost</strong> to connect all the </em><code>n</code><em> cities such that there is at least one path between each pair of cities</em>. If it is impossible to connect all the <code>n</code> cities, return <code>-1</code>,</p>

<p>The <strong>cost</strong> is the sum of the connections' costs used.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/04/20/1314_ex2.png" style="width: 161px; height: 141px;">
<pre><strong>Input:</strong> n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Choosing any 2 edges will connect all cities so we choose the minimum 2.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/04/20/1314_ex1.png" style="width: 136px; height: 91px;">
<pre><strong>Input:</strong> n = 4, connections = [[1,2,3],[3,4,4]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no way to connect all cities even if all edges are used.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= connections.length &lt;= 10<sup>4</sup></code></li>
	<li><code>connections[i].length == 3</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= n</code></li>
	<li><code>x<sub>i</sub> != y<sub>i</sub></code></li>
	<li><code>0 &lt;= cost<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Minimum Spanning Tree](https://leetcode.com/tag/minimum-spanning-tree/)

**Similar Questions**:
* [Minimum Cost to Reach City With Discounts (Medium)](https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/)

## Solution 1. Minimum Spanning Tree - Kruskal

```cpp
// OJ: https://leetcode.com/problems/connecting-cities-with-minimum-cost/
// Author: github.com/lzl124631x
// Time: O(ElogE)
// Space: O(N)
class UnionFind {
    vector<int> id;
    int cnt; 
public:
    UnionFind(int n) : id(n), cnt(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        --cnt;
        id[p] = q;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& E) {
        sort(begin(E), end(E), [](auto &a, auto &b) { return a[2] < b[2]; });
        UnionFind uf(n);
        int ans = 0;
        for (auto &e : E) {
            int u = e[0] - 1, v = e[1] - 1;
            if (uf.connected(u, v)) continue;
            uf.connect(u, v);
            ans += e[2];
        }
        return uf.getCount() == 1 ? ans : -1;
    }
};
```