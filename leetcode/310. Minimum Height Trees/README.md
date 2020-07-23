# [310. Minimum Height Trees (Medium)](https://leetcode.com/problems/minimum-height-trees/submissions/)

<p>For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.</p>

<p><b>Format</b><br>
The graph contains <code>n</code> nodes which are labeled from <code>0</code> to <code>n - 1</code>. You will be given the number <code>n</code> and a list of undirected <code>edges</code> (each edge is a pair of labels).</p>

<p>You can assume that no duplicate edges will appear in <code>edges</code>. Since all edges are undirected, <code>[0, 1]</code> is the same as <code>[1, 0]</code> and thus will not appear together in <code>edges</code>.</p>

<p><b>Example 1 :</b></p>

<pre><strong>Input:</strong> <code>n = 4</code>, <code>edges = [[1, 0], [1, 2], [1, 3]]</code>

        0
        |
        1
       / \
      2   3 

<strong>Output:</strong> <code>[1]</code>
</pre>

<p><b>Example 2 :</b></p>

<pre><strong>Input:</strong> <code>n = 6</code>, <code>edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]</code>

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

<strong>Output:</strong> <code>[3, 4]</code></pre>

<p><b>Note</b>:</p>

<ul>
	<li>According to the <a href="https://en.wikipedia.org/wiki/Tree_(graph_theory)" target="_blank">definition of tree on Wikipedia</a>: “a tree is an undirected graph in which any two vertices are connected by <i>exactly</i> one path. In other words, any connected graph without simple cycles is a tree.”</li>
	<li>The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.</li>
</ul>


**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Course Schedule (Medium)](https://leetcode.com/problems/course-schedule/)
* [Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii/)

## Solution 1.

Find the leave nodes, trim them from the graph. Repeat this process until the graph only has 1 or 2 nodes left.

```cpp
// OJ: https://leetcode.com/problems/minimum-height-trees
// Author: github.com/lzl124631x
// Time: O(E)
// Space: O(E)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& E) {
        if (n == 1) return { 0 };
        vector<int> indegree(n), ans;
        vector<vector<int>> G(n);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            indegree[u]++;
            indegree[v]++;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 1) q.push(i);
        }
        while (n > 2) {
            int cnt = q.size();
            while (cnt--) {
                int u = q.front();
                q.pop();
                --n;
                for (int v : G[u]) {
                    if (--indegree[v] == 1) q.push(v);
                }
            }
        }
        while (q.size()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
```