# [207. Course Schedule (Medium)](https://leetcode.com/problems/course-schedule/)

<p>There are a total of <code>numCourses</code> courses you have to take, labeled from <code>0</code> to <code>numCourses-1</code>.</p>

<p>Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: <code>[0,1]</code></p>

<p>Given the total number of courses and a list of prerequisite <b>pairs</b>, is it possible for you to finish all courses?</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> numCourses = 2, prerequisites = [[1,0]]
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;There are a total of 2 courses to take. 
&nbsp;            To take course 1 you should have finished course 0. So it is possible.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> numCourses = 2, prerequisites = [[1,0],[0,1]]
<strong>Output:</strong> false
<strong>Explanation:</strong>&nbsp;There are a total of 2 courses to take. 
&nbsp;            To take course 1 you should have finished course 0, and to take course 0 you should
&nbsp;            also have finished course 1. So it is impossible.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The input prerequisites is a graph represented by <b>a list of edges</b>, not adjacency matrices. Read more about <a href="https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs" target="_blank">how a graph is represented</a>.</li>
	<li>You may assume that there are no duplicate edges in the input prerequisites.</li>
	<li><code>1 &lt;=&nbsp;numCourses &lt;= 10^5</code></li>
</ul>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/)

**Similar Questions**:
* [Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii/)
* [Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii/)
* [Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii/)
* [Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii/)

## Solution 1. Topological Sort (BFS)

```cpp
// OJ: https://leetcode.com/problems/course-schedule/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& E) {
        vector<vector<int>> G(N);
        vector<int> indegree(N);
        for (auto &e : E) {
            G[e[1]].push_back(e[0]);
            ++indegree[e[0]];
        }
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        while (q.size()) {
            int u = q.front();
            q.pop();
            ++cnt;
            for (int v : G[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return cnt == N;
    }
};
```

## Solution 2. Topological Sort (DFS) 

```cpp
// OJ: https://leetcode.com/problems/course-schedule/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
    vector<int> state; // -1 unvisited, 0 visiting, 1 visited
    bool dfs(vector<vector<int>> &G, int u) {
        if (state[u] != -1) return state[u];
        state[u] = 0;
        for (int v : G[u]) {
            if (!dfs(G, v)) return false;
        }
        return state[u] = 1;
    }
public:
    bool canFinish(int N, vector<vector<int>>& E) {
        vector<vector<int>> G(N);
        state.assign(N, -1);
        for (auto &e : E) G[e[1]].push_back(e[0]);
        for (int i = 0; i < N; ++i) {
            if (!dfs(G, i)) return false;
        }
        return true;
    }
};
```