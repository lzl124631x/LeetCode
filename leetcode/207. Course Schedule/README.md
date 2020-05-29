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
    bool canFinish(int N, vector<vector<int>>& A) {
        unordered_map<int, vector<int>> G;
        vector<int> indegree(N);
        for (auto &e : A) {
            G[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        int visited = 0;
        while (q.size()) {
            int u = q.front();
            q.pop();
            ++visited;
            for (int v : G[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return visited == N;
    }
};
```

## Solution 2. DFS

Within one DFS session, if we see the same node twice, there has a circle in the graph and we should return `false`.

Once an edge has been used, we remove the edge to prevent going through it again.

```cpp
// OJ: https://leetcode.com/problems/course-schedule/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
    unordered_map<int, vector<int>> next;
    vector<bool> seen;
    bool hasCircle(int u) {
        if (seen[u]) return true;
        seen[u] = true;
        auto &n = next[u];
        for (int i = n.size() - 1; i >= 0; --i) {
            if (hasCircle(n[i])) return true;
            n.pop_back();
        }
        return seen[u] = false;
    }
public:
    bool canFinish(int N, vector<vector<int>>& E) {
        for (auto e : E) next[e[1]].push_back(e[0]);
        seen.assign(N, false);
        for (int i = 0; i < N; ++i) {
            if (hasCircle(i)) return false;
        }
        return true;
    }
};
```

## Solution 3. Topological Sort (DFS) 

```cpp
// OJ: https://leetcode.com/problems/course-schedule/
// Author: github.com/lzl124631x
// Time: O(E + V)
// Space: O(E + V)
class Solution {
    unordered_map<int, vector<int>> G;
    vector<int> seen;
    bool hasCircle(int u) {
        if (seen[u]) return seen[u] == -1;
        seen[u] = -1;
        for (int v : G[u]) {
            if (hasCircle(v)) return true;
        }
        seen[u] = 1;
        return false;
    }
public:
    bool canFinish(int N, vector<vector<int>>& E) {
        for (auto e : E) G[e[1]].push_back(e[0]);
        seen.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            if (seen[i]) continue;
            if (hasCircle(i)) return false;
        }
        return true;
    }
};
```