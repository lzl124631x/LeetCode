# [1462. Course Schedule IV (Medium)](https://leetcode.com/problems/course-schedule-iv/)

<p>There are a total of <code>n</code> courses you have to take, labeled from <code>0</code> to <code>n-1</code>.</p>

<p>Some courses may have direct prerequisites, for example, to take course 0 you have first to take course 1, which is expressed as a pair: <code>[1,0]</code></p>

<p>Given the total number of courses <code>n</code>,&nbsp;a list of direct&nbsp;<code>prerequisite</code> <strong>pairs</strong> and a list of <code>queries</code> <strong>pairs</strong>.</p>

<p>You should answer for each <code>queries[i]</code> whether the course <code>queries[i][0]</code> is a&nbsp;prerequisite of the course&nbsp;<code>queries[i][1]</code> or not.</p>

<p>Return <em>a list of boolean</em>, the answers to the given <code>queries</code>.</p>

<p>Please note that if course <strong>a</strong> is a prerequisite of course <strong>b</strong> and course <strong>b</strong> is a prerequisite&nbsp;of course <strong>c</strong>, then, course <strong>a</strong> is a&nbsp;prerequisite of course <strong>c</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/17/graph.png" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
<strong>Output:</strong> [false,true]
<strong>Explanation:</strong> course 0 is not a prerequisite of course 1 but the opposite is true.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2, prerequisites = [], queries = [[1,0],[0,1]]
<strong>Output:</strong> [false,false]
<strong>Explanation:</strong> There are no prerequisites and each course is independent.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/17/graph-1.png" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> n = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
<strong>Output:</strong> [true,true]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 3, prerequisites = [[1,0],[2,0]], queries = [[0,1],[2,0]]
<strong>Output:</strong> [false,true]
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> n = 5, prerequisites = [[0,1],[1,2],[2,3],[3,4]], queries = [[0,4],[4,0],[1,3],[3,0]]
<strong>Output:</strong> [true,false,true,false]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= prerequisite.length &lt;= (n * (n - 1) / 2)</code></li>
	<li><code>0 &lt;= prerequisite[i][0], prerequisite[i][1] &lt; n</code></li>
	<li><code>prerequisite[i][0] != prerequisite[i][1]</code></li>
	<li>The prerequisites graph has no cycles.</li>
	<li>The prerequisites graph has no repeated edges.</li>
	<li><code>1 &lt;= queries.length &lt;= 10^4</code></li>
	<li><code>queries[i][0] != queries[i][1]</code></li>
</ul>


**Related Topics**:  
[Graph](https://leetcode.com/tag/graph/)

## Solution 1. DFS

We can first build a directed graph given the `prerequisite`. Then for each query, we DFS to check we can reach `q[1]` from `q[0]`. To save computation, we can memoize the result of any `from, to` node pairs we've seen along the DFS process.

```cpp
// OJ: https://leetcode.com/problems/course-schedule-iv/
// Author: github.com/lzl124631x
// Time: O(min(N^2, Q))
// Space: O(N^2)
class Solution {
    vector<vector<int>> G, m;
    bool dfs(int from, int to) {
        if (m[from][to] != -1) return m[from][to];
        for (int v : G[from]) {
            if (dfs(v, to)) return m[from][to] = 1;
        }
        return m[from][to] = 0;
    }
public:
    vector<bool> checkIfPrerequisite(int N, vector<vector<int>>& E, vector<vector<int>>& Q) {
        G.assign(N, {});
        m.assign(N, vector<int>(N, -1));
        for (int i = 0; i < N; ++i) m[i][i] = 1;
        for (auto &e : E) G[e[0]].push_back(e[1]);
        vector<bool> ans;
        for (auto &q : Q) ans.push_back(dfs(q[0], q[1]));
        return ans;
    }
};
```

## Solution 2. Floyd-Warshall

We can use the Floyd-Warshall algorithm to fine all the shortest paths of any node pairs in a weighted graph. Here we can make simple adjustment to it to just store whether any node pairs are reachable.

```cpp
// OJ: https://leetcode.com/problems/course-schedule-iv/
// Author: github.com/lzl124631x
// Time: O(N^3 + Q)
// Space: O(N^2)
class Solution {
public:
    vector<bool> checkIfPrerequisite(int N, vector<vector<int>>& E, vector<vector<int>>& Q) {
        vector<vector<bool>> m(N, vector<bool>(N));
        for (auto &e : E) m[e[0]][e[1]] = true;
        for (int i = 0; i < N; ++i) {
            for (int u = 0; u < N; ++u) {
                for (int v = 0; v < N; ++v) {
                    m[u][v] = m[u][v] || (m[u][i] && m[i][v]);
                }
            }
        }
        vector<bool> ans;
        for (auto &q : Q) ans.push_back(m[q[0]][q[1]]);
        return ans;
    }
};
```

## Solution 3. Topological Sort

```cpp
// OJ: https://leetcode.com/problems/course-schedule-iv/
// Author: github.com/lzl124631x
// Time: O(N^2 + Q)
// Space: O(N^2)
class Solution {
public:
    vector<bool> checkIfPrerequisite(int N, vector<vector<int>>& P, vector<vector<int>>& Q) {
        vector<vector<int>> G(N);
        vector<int> indegree(N), seen(N);
        vector<unordered_set<int>> pre(N);
        for (auto &p : P) {
            int u = p[0], v = p[1];
            G[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                for (int p : pre[u]) {
                    pre[v].insert(p);
                }
                pre[v].insert(u);
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        vector<bool> ans;
        for (auto q : Q) {
            ans.push_back(pre[q[1]].count(q[0]));
        }
        return ans;
    }
};
```