# [1136. Parallel Courses (Medium)](https://leetcode.com/problems/parallel-courses/)

<p>You are given an integer <code>n</code>, which indicates that there are <code>n</code> courses labeled from <code>1</code> to <code>n</code>. You are also given an array <code>relations</code> where <code>relations[i] = [prevCourse<sub>i</sub>, nextCourse<sub>i</sub>]</code>, representing a prerequisite relationship between course <code>prevCourse<sub>i</sub></code> and course <code>nextCourse<sub>i</sub></code>: course <code>prevCourse<sub>i</sub></code> has to be taken before course <code>nextCourse<sub>i</sub></code>.</p>

<p>In one semester, you can take <strong>any number</strong> of courses as long as you have taken all the prerequisites in the <strong>previous</strong> semester for the courses you are taking.</p>

<p>Return <em>the <strong>minimum</strong> number of semesters needed to take all courses</em>. If there is no way to take all the courses, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/24/course1graph.jpg" style="width: 222px; height: 222px;">
<pre><strong>Input:</strong> n = 3, relations = [[1,3],[2,3]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The figure above represents the given graph.
In the first semester, you can take courses 1 and 2.
In the second semester, you can take course 3.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/24/course2graph.jpg" style="width: 222px; height: 222px;">
<pre><strong>Input:</strong> n = 3, relations = [[1,2],[2,3],[3,1]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> No course can be studied because they are prerequisites of each other.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
	<li><code>1 &lt;= relations.length &lt;= 5000</code></li>
	<li><code>relations[i].length == 2</code></li>
	<li><code>1 &lt;= prevCourse<sub>i</sub>, nextCourse<sub>i</sub> &lt;= n</code></li>
	<li><code>prevCourse<sub>i</sub> != nextCourse<sub>i</sub></code></li>
	<li>All the pairs <code>[prevCourse<sub>i</sub>, nextCourse<sub>i</sub>]</code> are <strong>unique</strong>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Graph](https://leetcode.com/tag/graph/), [Topological Sort](https://leetcode.com/tag/topological-sort/)

**Similar Questions**:
* [Course Schedule II (Medium)](https://leetcode.com/problems/course-schedule-ii/)
* [Parallel Courses II (Hard)](https://leetcode.com/problems/parallel-courses-ii/)
* [Parallel Courses III (Hard)](https://leetcode.com/problems/parallel-courses-iii/)

## Solution 1. Topological Sort (BFS)

```cpp
// OJ: https://leetcode.com/problems/parallel-courses/
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N + E)
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& E) {
        vector<vector<int>> G(n);
        vector<int> indegree(n);
        for (auto &e : E) {
            int u = e[0] - 1, v = e[1] - 1;
            G[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        int step = 0, seen = 0;
        while (q.size()) {
            int cnt = q.size();
            seen += cnt;
            while (cnt--) {
                int u = q.front();
                q.pop();
                for (int v : G[u]) {
                    if (--indegree[v] == 0) q.push(v);
                }
            }
            ++step;
        }
        return seen == n ? step : -1;
    }
};
```

## Solution 2. Topological Sort (DFS)

```cpp
// OJ: https://leetcode.com/problems/parallel-courses/
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& E) {
        vector<vector<int>> G(n);
        for (auto &e : E) {
            int u = e[0] - 1, v = e[1] - 1;
            G[u].push_back(v);
        }
        vector<int> state(n, -1); // -1 -> unvisited, 0 -> visiting/invalid, positive number -> visited, depth
        function<int(int)> dfs = [&](int u) {
            if (state[u] != -1) return state[u];
            state[u] = 0;
            int ans = 0;
            for (int v : G[u]) {
                int d = dfs(v);
                if (d == 0) return 0;
                ans = max(ans, d);
            }
            return state[u] = 1 + ans;
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int depth = dfs(i);
            if (!depth) return -1;
            ans = max(ans, depth);
        }
        return ans;
    }
};
```