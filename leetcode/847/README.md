# [847. Shortest Path Visiting All Nodes (Hard)](https://leetcode.com/problems/shortest-path-visiting-all-nodes/)

<p>You have an undirected, connected graph of <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>. You are given an array <code>graph</code> where <code>graph[i]</code> is a list of all the nodes connected with node <code>i</code> by an edge.</p>

<p>Return <em>the length of the shortest path that visits every node</em>. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/12/shortest1-graph.jpg" style="width: 222px; height: 183px;">
<pre><strong>Input:</strong> graph = [[1,2,3],[0],[0],[0]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> One possible path is [1,0,2,0,3]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/05/12/shortest2-graph.jpg" style="width: 382px; height: 222px;">
<pre><strong>Input:</strong> graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> One possible path is [0,1,4,2,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == graph.length</code></li>
	<li><code>1 &lt;= n &lt;= 12</code></li>
	<li><code>0 &lt;= graph[i].length &lt;&nbsp;n</code></li>
	<li><code>graph[i]</code> does not contain <code>i</code>.</li>
	<li>If <code>graph[a]</code> contains <code>b</code>, then <code>graph[b]</code> contains <code>a</code>.</li>
	<li>The input graph is always connected.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Bitmask](https://leetcode.com/tag/bitmask/)

## Solution 1. BFS Among States

Let `(u, mask)` be a state where we've visited nodes represented by `mask` and the last node visited is `u`.

For a neighbor node of `u`, we can transition from `(u, mask)` to `(v, mask | (1 << v))` in one step.

We can BFS from initial states `(i, 1 << i)` (`0 <= i < N`) and count the steps needed to make `mask` the full graph.

```cpp
// OJ: https://leetcode.com/problems/shortest-path-visiting-all-nodes/
// Author: github.com/lzl124631x
// Time: O(2^N * N)
// Space: O(2^N * N)
// Ref: https://leetcode.com/problems/shortest-path-visiting-all-nodes/discuss/135809/Fast-BFS-Solution-(46ms)-Clear-Detailed-Explanation-Included
class Solution {
    int getKey(int i, int mask) {
        return (i << 12) + mask;
    }
public:
    int shortestPathLength(vector<vector<int>>& G) {
        int N = G.size(), all = (1 << N) - 1, step = 0;
        queue<int> q;
        unordered_set<int> seen;
        for (int i = 0; i < N; ++i) {
            int k = getKey(i, 1 << i);
            q.push(k);
            seen.insert(k);
        }
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                int k = q.front(), u = k >> 12, mask = k & ((1 << 12) - 1);
                q.pop();
                if (mask == all) return step;
                for (int v : G[u]) {
                    int next = getKey(v, mask | (1 << v));
                    if (seen.count(next)) continue;
                    seen.insert(next);
                    q.push(next);
                }
            }
            ++step;
        }
        return -1;
    }
};
```