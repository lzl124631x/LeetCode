# [207. Course Schedule (Medium)](https://leetcode.com/problems/course-schedule)

<p>There are a total of <code>numCourses</code> courses you have to take, labeled from <code>0</code> to <code>numCourses - 1</code>. You are given an array <code>prerequisites</code> where <code>prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that you <strong>must</strong> take course <code>b<sub>i</sub></code> first if you want to take course <code>a<sub>i</sub></code>.</p>
<ul>
	<li>For example, the pair <code>[0, 1]</code>, indicates that to take course <code>0</code> you have to first take course <code>1</code>.</li>
</ul>
<p>Return <code>true</code> if you can finish all courses. Otherwise, return <code>false</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> numCourses = 2, prerequisites = [[1,0]]
<strong>Output:</strong> true
<strong>Explanation:</strong> There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> numCourses = 2, prerequisites = [[1,0],[0,1]]
<strong>Output:</strong> false
<strong>Explanation:</strong> There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= numCourses &lt;= 2000</code></li>
	<li><code>0 &lt;= prerequisites.length &lt;= 5000</code></li>
	<li><code>prerequisites[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; numCourses</code></li>
	<li>All the pairs prerequisites[i] are <strong>unique</strong>.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/)

**Similar Questions**:
* [Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii/)
* [Graph Valid Tree (Medium)](https://leetcode.com/problems/graph-valid-tree/)
* [Minimum Height Trees (Medium)](https://leetcode.com/problems/minimum-height-trees/)
* [Course Schedule III (Hard)](https://leetcode.com/problems/course-schedule-iii/)
* [Build a Matrix With Conditions (Hard)](https://leetcode.com/problems/build-a-matrix-with-conditions/)

## Solution 1. Topological Sort (BFS)

```cpp
// OJ: https://leetcode.com/problems/course-schedule/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& E) {
        vector<vector<int>> G(n);
        vector<int> indegree(n);
        for (auto &e : E) {
            G[e[1]].push_back(e[0]);
            ++indegree[e[0]];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            --n;
            for (int v : G[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return n == 0;
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
public:
    bool canFinish(int n, vector<vector<int>>& E) {
        vector<vector<int>> G(n);
        for (auto &e : E) G[e[1]].push_back(e[0]);
        vector<int> state(n, -1); // -1 unvisited, 0 visiting, 1 visited
        function<bool(int)> dfs = [&](int u) -> bool {
            if (state[u] != -1) return state[u]; 
            state[u] = 0;
            for (int v : G[u]) {
                if (!dfs(v)) return false;
            }
            return state[u] = 1;
        };
        for (int i = 0; i < n; ++i) {
            if (!dfs(i)) return false;
        }
        return true;
    }
};
```