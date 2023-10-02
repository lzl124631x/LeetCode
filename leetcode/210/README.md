# [210. Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii)

<p>There are a total of <code>numCourses</code> courses you have to take, labeled from <code>0</code> to <code>numCourses - 1</code>. You are given an array <code>prerequisites</code> where <code>prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that you <strong>must</strong> take course <code>b<sub>i</sub></code> first if you want to take course <code>a<sub>i</sub></code>.</p>
<ul>
	<li>For example, the pair <code>[0, 1]</code>, indicates that to take course <code>0</code> you have to first take course <code>1</code>.</li>
</ul>
<p>Return <em>the ordering of courses you should take to finish all courses</em>. If there are many valid answers, return <strong>any</strong> of them. If it is impossible to finish all courses, return <strong>an empty array</strong>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> numCourses = 2, prerequisites = [[1,0]]
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
<strong>Output:</strong> [0,2,1,3]
<strong>Explanation:</strong> There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> numCourses = 1, prerequisites = []
<strong>Output:</strong> [0]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= numCourses &lt;= 2000</code></li>
	<li><code>0 &lt;= prerequisites.length &lt;= numCourses * (numCourses - 1)</code></li>
	<li><code>prerequisites[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; numCourses</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>All the pairs <code>[a<sub>i</sub>, b<sub>i</sub>]</code> are <strong>distinct</strong>.</li>
</ul>

**Companies**:
[TikTok](https://leetcode.com/company/tiktok), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/)

**Similar Questions**:
* [Course Schedule (Medium)](https://leetcode.com/problems/course-schedule/)
* [Alien Dictionary (Hard)](https://leetcode.com/problems/alien-dictionary/)
* [Minimum Height Trees (Medium)](https://leetcode.com/problems/minimum-height-trees/)
* [Sequence Reconstruction (Medium)](https://leetcode.com/problems/sequence-reconstruction/)
* [Course Schedule III (Hard)](https://leetcode.com/problems/course-schedule-iii/)
* [Parallel Courses (Medium)](https://leetcode.com/problems/parallel-courses/)
* [Find All Possible Recipes from Given Supplies (Medium)](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/)
* [Build a Matrix With Conditions (Hard)](https://leetcode.com/problems/build-a-matrix-with-conditions/)
* [Sort Array by Moving Items to Empty Space (Hard)](https://leetcode.com/problems/sort-array-by-moving-items-to-empty-space/)

## Solution 1. Topological Sort (BFS)

```cpp
// OJ: https://leetcode.com/problems/course-schedule-ii/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& E) {
        vector<vector<int>> G(n);
        vector<int> indegree(n), ans;
        for (auto &e : E) {
            G[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v : G[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return ans.size() == n ? ans : vector<int>{};
    }
};
```

## Solution 2. Topological Sort (DFS)

```cpp
// OJ: https://leetcode.com/problems/course-schedule-ii/
// Author: github.com/lzl124631x
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& E) {
        vector<vector<int>> G(n);
        for (auto &e : E) G[e[1]].push_back(e[0]);
        vector<int> ans, state(n, -1); // -1 unvisited, 0 visiting, 1 visited
        function<bool(int)> dfs = [&](int u) -> bool {
            if (state[u] != -1) return state[u];
            state[u] = 0;
            for (int v : G[u]) {
                if (!dfs(v)) return false;
            }
            ans.push_back(u);
            return state[u] = 1;
        };
        for (int i = 0; i < n; ++i) {
            if (!dfs(i)) return {};
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```