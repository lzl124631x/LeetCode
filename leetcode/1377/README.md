# [1377. Frog Position After T Seconds (Hard)](https://leetcode.com/problems/frog-position-after-t-seconds/)

<p>Given an undirected tree&nbsp;consisting of <code>n</code> vertices numbered from 1 to <code>n</code>. A frog starts jumping&nbsp;from the <strong>vertex 1</strong>. In one second, the frog&nbsp;jumps from its&nbsp;current&nbsp;vertex to another <strong>unvisited</strong> vertex if they are directly connected. The frog can not jump back to a visited vertex.&nbsp;In case the frog can jump to several vertices it jumps randomly to one of them with the same probability, otherwise, when the frog can not jump to any unvisited vertex it jumps forever on the same vertex.&nbsp;</p>

<p>The edges of the undirected tree&nbsp;are given in the array <code>edges</code>, where <code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>]</code> means that exists an edge connecting directly the vertices <code>from<sub>i</sub></code> and <code>to<sub>i</sub></code>.</p>

<p><em>Return the probability that after <code>t</code> seconds the frog is on the vertex <code><font face="monospace">target</font></code>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/20/frog_2.png" style="width: 350px; height: 236px;"></p>

<pre><strong>Input:</strong> n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
<strong>Output:</strong> 0.16666666666666666 
<strong>Explanation: </strong>The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 probability to the vertex 2 after <strong>second 1</strong> and then jumping with 1/2 probability to vertex 4 after <strong>second 2</strong>. Thus the probability for the frog is on the vertex 4 after 2 seconds is 1/3 * 1/2 = 1/6 = 0.16666666666666666. 
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/02/20/frog_3.png" style="width: 350px; height: 236px;"></strong></p>

<pre><strong>Input:</strong> n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
<strong>Output:</strong> 0.3333333333333333
<strong>Explanation: </strong>The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 = 0.3333333333333333 probability to the vertex 7 after <strong>second 1</strong>. 
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 20, target = 6
<strong>Output:</strong> 0.16666666666666666
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>edges.length == n-1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>1 &lt;= edges[i][0], edges[i][1] &lt;= n</code></li>
	<li><code>1 &lt;= t&nbsp;&lt;= 50</code></li>
	<li><code>1 &lt;= target&nbsp;&lt;= n</code></li>
	<li>Answers within <code>10^-5</code> of the actual value will be accepted as correct.</li>
</ul>

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. DFS

Build the tree then try to generate the path from `1` to `target`.

* If `t` is not enough for reaching `target`, i.e. `t + 1 < path.size()`, then return `0`
* If `t` is too long that the frog jumps further than the `target`, i.e. `t + 1 > path.size() && tree[path.back()].size()`, then return `0`.
* Otherwise, the answer is `1.0 / k` where `k` is the product of all the count of branches from the root to the parent of `target`.

```cpp
// OJ: https://leetcode.com/problems/frog-position-after-t-seconds/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    unordered_map<int, vector<int>> g, nei;
    bool dfs(int start, int target, vector<int>&path) {
        path.push_back(start);
        if (start == target) return true;
        for (int n : g[start]) {
            if (dfs(n, target, path)) return true;
        }
        path.pop_back();
        return false;
    }
    void buildTree(int start, int p) {
        for (int n : nei[start]) {
            if (n == p) continue;
            g[start].push_back(n);
            buildTree(n, start);
        }
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        for (auto & e : edges) {
            nei[e[0]].push_back(e[1]);
            nei[e[1]].push_back(e[0]);
        }
        buildTree(1, -1);
        vector<int> path;
        dfs(1, target, path);
        if (t + 1 < path.size() || (t + 1 > path.size() && g[path.back()].size())) return 0;
        int cnt = 1;
        for (int i = 0; i < path.size() - 1; ++i) cnt *= g[path[i]].size();
        return 1. / cnt;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/frog-position-after-t-seconds/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/frog-position-after-t-seconds/discuss/532571/Python-DFS
class Solution {
    vector<vector<int>> g;
    vector<bool> seen;
    double dfs(int node, int t, int target) {
        seen[node] = true;
        int cnt = g[node].size() - (node != 1);
        if (!t) return node == target;
        if (node == target) return !cnt;
        double ans = 0;
        for (int n : g[node]) {
            if (seen[n]) continue;
            if (ans = dfs(n, t - 1, target)) break;
        }
        if (ans) ans /= cnt;
        return ans;
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        g.resize(n + 1);
        seen.resize(n + 1);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return dfs(1, t, target);
    }
};
```