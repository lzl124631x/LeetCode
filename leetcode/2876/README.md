# [2876. Count Visited Nodes in a Directed Graph (Hard)](https://leetcode.com/problems/count-visited-nodes-in-a-directed-graph)

<p>There is a <strong>directed</strong> graph consisting of <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code> and <code>n</code> directed edges.</p>

<p>You are given a <strong>0-indexed</strong> array <code>edges</code> where <code>edges[i]</code> indicates that there is an edge from node <code>i</code> to node <code>edges[i]</code>.</p>

<p>Consider the following process on the graph:</p>

<ul>
	<li>You start from a node <code>x</code> and keep visiting other nodes through edges until you reach a node that you have already visited before on this <strong>same</strong> process.</li>
</ul>

<p>Return <em>an array </em><code>answer</code><em> where </em><code>answer[i]</code><em> is the number of <strong>different</strong> nodes that you will visit if you perform the process starting from node </em><code>i</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/08/31/graaphdrawio-1.png" />
<pre>
<strong>Input:</strong> edges = [1,2,0,0]
<strong>Output:</strong> [3,3,3,4]
<strong>Explanation:</strong> We perform the process starting from each node in the following way:
- Starting from node 0, we visit the nodes 0 -&gt; 1 -&gt; 2 -&gt; 0. The number of different nodes we visit is 3.
- Starting from node 1, we visit the nodes 1 -&gt; 2 -&gt; 0 -&gt; 1. The number of different nodes we visit is 3.
- Starting from node 2, we visit the nodes 2 -&gt; 0 -&gt; 1 -&gt; 2. The number of different nodes we visit is 3.
- Starting from node 3, we visit the nodes 3 -&gt; 0 -&gt; 1 -&gt; 2 -&gt; 0. The number of different nodes we visit is 4.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/08/31/graaph2drawio.png" style="width: 191px; height: 251px;" />
<pre>
<strong>Input:</strong> edges = [1,2,3,4,0]
<strong>Output:</strong> [5,5,5,5,5]
<strong>Explanation:</strong> Starting from any node we can visit every node in the graph in the process.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= edges[i] &lt;= n - 1</code></li>
	<li><code>edges[i] != i</code></li>
</ul>


**Companies**:
[BNY Mellon](https://leetcode.com/company/bny-mellon)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Graph](https://leetcode.com/tag/graph), [Memoization](https://leetcode.com/tag/memoization)

**Hints**:
* Consider if the graph was only one cycle, what will be the answer for each node?
* The actual graph will always consist of at least one cycle and some other nodes.
* Calculate the answer for nodes in cycles the same way as in hint 1. How do you calculate the answer for the remaining nodes?

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/count-visited-nodes-in-a-directed-graph
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& E) {
        int N = E.size();
        vector<int> dist(N, -1), state(N, -1); // -1 unvisited, 0 visiting, 1 visited
        function<int(int, int)> dfs = [&](int u, int d) {
            if (state[u] == 1) return dist[u]; // if this node has been visited, return dist[u] directly
            if (state[u] == 0) { // if this node is being visited, we've found a cycle
                state[u] = 1; // mark this node as visited. Later when we backtrack, if we found that the current value is already marked as visited, we know that we've done visiting the cycle
                dist[u] = d - dist[u]; 
                return -dist[u]; // we return negative dist to indicate that we are still in the cycle
            }
            state[u] = 0;
            dist[u] = d;
            int ans = dfs(E[u], d + 1);
            if (ans < 0) { // If the next distance is negative, it means that we are still in the cycle
                if (state[u] == 1) return -ans; // this node is the last node of the cycle, we can start returning positive dist
                dist[u] = -ans; // we keep logging the same distance within cycle
                state[u] = 1;
                return ans;
            }
            state[u] = 1;
            return dist[u] = ans + 1; // we are out of cycle, dist[u] should be 1 plus next distance
        };
        for (int i = 0; i < N; ++i) {
            if (dist[i] != -1) continue;
            dfs(i, 0);
        }
        return dist;
    }
};
```